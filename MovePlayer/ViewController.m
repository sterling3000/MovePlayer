//
//  ViewController.m
//  MovePlayer
//
//  Created by Zhiye Li on 7/30/15.
//  Copyright (c) 2015 Sterling. All rights reserved.
//

#import "ViewController.h"
#import "UIImageView+WebCache.h"
#import <CoreMotion/CoreMotion.h>
#import <VevoSDK_Internal/VMMoviePlayerController.h>
#import <VevoSDK_Internal/VMApiFacade.h>
#import <VevoSDK_Internal/VMMoviePlayerController_Private.h>

@interface ViewController () <VMMoviePlayerControllerDelegate>

@property (nonatomic) UIView            *playerBaseView;
@property (nonatomic) UIImageView       *thumbnailView;
@property (nonatomic) CMMotionManager   *motionManager;
@property (nonatomic) VMMoviePlayerController       *player;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    CGFloat height = CGRectGetHeight(self.view.frame);
    CGFloat width = height*16./9;
    CGFloat x = CGRectGetWidth(self.view.frame)/2 - width/2;
    NSString *imageUrl = @"http://img.cache.vevo.com/Content/VevoImages/video/851E27D7CB54BED811E0D7F52365E7D9201536115833385.jpg";
    self.thumbnailView = [[UIImageView alloc] initWithFrame:CGRectMake(x, 0, width, height)];
    [self.thumbnailView sd_setImageWithURL:[NSURL URLWithString:imageUrl] placeholderImage:nil];
    [self.view addSubview:self.thumbnailView];
    
    UIImage *buttonImg = [[UIImage imageNamed:@"icon_playall_pink"] imageWithRenderingMode:UIImageRenderingModeAlwaysTemplate];
    UIButton *playButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [playButton setImage:buttonImg forState:UIControlStateNormal];
    //[playButton sizeToFit];
    playButton.bounds = CGRectMake(0, 0, buttonImg.size.width * 2, buttonImg.size.height*2);
    playButton.backgroundColor = [UIColor colorWithWhite:0 alpha:.5];
    playButton.layer.cornerRadius = buttonImg.size.width;
    playButton.center = CGPointMake(self.view.frame.size.width/2, self.view.frame.size.height/2);
    playButton.tintColor = [UIColor grayColor];
    //[self.view addSubview:playButton];
    //[playButton addTarget:self action:@selector(onButtonTapped:) forControlEvents:UIControlEventTouchUpInside];
    
    
    self.motionManager = [CMMotionManager new];
//    self.motionManager.deviceMotionUpdateInterval = 1;
//    self.motionManager.accelerometerUpdateInterval = 1;
//    self.motionManager.magnetometerUpdateInterval = 1;
//    self.motionManager.gyroUpdateInterval = 1;
    
    __block CMAttitude *initialAttitude = self.motionManager.deviceMotion.attitude;
    __weak ViewController *weakSelf = self;
    BOOL canUseDeviceMotion = self.motionManager.deviceMotionAvailable;
    if (canUseDeviceMotion){
        [self.motionManager startDeviceMotionUpdatesToQueue:[NSOperationQueue new]
                                           withHandler:^(CMDeviceMotion *motion, NSError *error) {
                                               //NSLog(@"New Device Motion data: %@", motion);
                                               
                                               if (!initialAttitude)
                                                   initialAttitude = weakSelf.motionManager.deviceMotion.attitude;
                                               // translate the attitude
                                               [motion.attitude multiplyByInverseOfAttitude:initialAttitude];
                                               
                                               // calculate magnitude of the change from our initial attitude
                                               double magnitude = [ViewController magnitudeFromAttitude:motion.attitude];
                                               
                                               NSLog(@"magnitude: %f", magnitude);
                                               
                                               dispatch_async(dispatch_get_main_queue(), ^{
                                               
                                                   [self moveAround:magnitude];
                                               });
        
                                               
//                                               // show the prompt
//                                               if (!showingPrompt && (magnitude > showPromptTrigger)) {
//                                                   showingPrompt = YES;
//                                                   
//                                                   PromptViewController *promptViewController = [weakSelf.storyboard instantiateViewControllerWithIdentifier:@"PromptViewController"];
//                                                   promptViewController.modalTransitionStyle = UIModalTransitionStyleCrossDissolve;
//                                                   [weakSelf presentViewController:promptViewController animated:YES completion:nil];
//                                               }
//                                               
//                                               // hide the prompt
//                                               if (showingPrompt && (magnitude < showAnswerTrigger)) {
//                                                   showingPrompt = NO;
//                                                   [weakSelf dismissViewControllerAnimated:YES completion:nil];
//                                               }
                                               
                                           }];
//
//        __block CGFloat accel = 0;
//        [self.motionManager startAccelerometerUpdatesToQueue:[NSOperationQueue new]
//                                            withHandler:^(CMAccelerometerData *accelerometerData, NSError *error) {
//                                                //NSLog(@"accelerometer data: %@", accelerometerData);
//                                                
//                                                accel += accelerometerData.acceleration.x;
//                                                
//                                                dispatch_async(dispatch_get_main_queue(), ^{
//                                                    
//                                                    [self moveAround:accel];
//                                                });
//                                                
//                                            }];
//
//        [self.motionManager startMagnetometerUpdatesToQueue:[NSOperationQueue new]
//                                                withHandler:^(CMMagnetometerData *magnetometerData, NSError *error) {
//                                                    //NSLog(@"manetic data: %@", magnetometerData);
//                                                    
//                                                    dispatch_async(dispatch_get_main_queue(), ^{
//                                                        
//                                                        [self moveAround:accel];
//                                                    });
//                                                }];
//        
//        [self.motionManager startGyroUpdatesToQueue:[NSOperationQueue new] withHandler:^(CMGyroData *gyroData, NSError *error){
//            NSLog(@"gyroscope data: %@", gyroData);
//        }];
    }
    
    [self loadAndPlayVideos:@"GB1101400818"];
}

- (BOOL)prefersStatusBarHidden
{
    return YES;
}

- (void)moveAround:(CGFloat)x
{
    CGFloat xCenterRef = self.view.frame.size.width/2;
    CGFloat xCenterMax = self.playerBaseView.frame.size.width/2;
    CGFloat xCenterMin = self.view.frame.size.width - self.playerBaseView.frame.size.width/2;
    
    CGFloat xCenterNew = xCenterRef += x;
    xCenterNew = fmax(xCenterMin, xCenterNew);
    xCenterNew = fmin(xCenterMax, xCenterNew);
    
    self.playerBaseView.center = CGPointMake(xCenterNew, self.view.frame.size.height/2);
}


- (void)loadAndPlayVideos:(NSString *)isrc
{
    [[VMApiFacade sharedInstance] getVideoWithIsrc:isrc completion:^(BOOL success, VMVideo *video, VMError *error){
    
        if (success) {
            
            self.playerBaseView = [[UIView alloc] initWithFrame:self.thumbnailView.bounds];
            self.player = [[VMMoviePlayerController alloc] initWithBaseView:self.playerBaseView];
            self.player.delegate = self;
            self.player.disableArtistVideos = YES;
            self.player.controlStyle = VMMovieControlStyleFullscreen;
            self.player.hideDefaultCloseButton = YES;
            self.player.hideDefaultVevoLogo = YES;
            self.player.enableContinuousPlay = YES;
            [self.player playVideo:video];
        }
    }];
}

- (void)onButtonTapped:(id)sender
{
    if (self.player)
        return;
    
    self.playerBaseView = [[UIView alloc] initWithFrame:self.thumbnailView.bounds];
    self.player = [[VMMoviePlayerController alloc] initWithBaseView:self.playerBaseView];
    self.player.delegate = self;
    self.player.disableArtistVideos = YES;
    self.player.controlStyle = VMMovieControlStyleEmbedded;
    self.player.hideDefaultCloseButton = YES;
    self.player.hideDefaultVevoLogo = YES;
    self.player.enableContinuousPlay = YES;
    
    // Start playing the video
    [self.player playVideoByISRC:@"GB1101400818"];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

+ (double)magnitudeFromAttitude:(CMAttitude *)attitude {
    return sqrt(pow(attitude.roll, 2.0f) + pow(attitude.yaw, 2.0f) + pow(attitude.pitch, 2.0f));
}

/**
 Called right before the movie player is about start playing a video.
 @param player The player controller object.
 */
- (void)movieplayerWillStartPlaying:(VMMoviePlayerController *)player {
    
    if (self.playerBaseView.superview == nil)
        [self showPlayerView];
}

- (void)moviePlayerDidStartPlayingPreroll:(VMMoviePlayerController *)player {
    
    if (self.playerBaseView.superview == nil)
        [self showPlayerView];
}

- (void)showPlayerView
{
    self.playerBaseView.alpha = 0;
    [self.view addSubview:self.playerBaseView];
    [UIView animateWithDuration:2. animations:^{
        self.playerBaseView.alpha = 1;
        self.thumbnailView.transform = CGAffineTransformScale(CGAffineTransformIdentity, 3., 3.);
        self.thumbnailView.alpha = 0;
    } completion:^(BOOL finished){
        
    }];
}

@end
