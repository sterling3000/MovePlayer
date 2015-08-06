//
//  VMNowPost.h
//  vevo-ios-sdk
//
//  Created by Sterling Li on 10/16/13.
//  Copyright (c) 2013 Vevo. All rights reserved.
//

#import "VMEntityBase.h"

typedef NS_ENUM(NSInteger, VMNowPostType) {
    
    VM_NOW_POST_TYPE_DEFAULT = 0,
    VM_NOW_POST_TYPE_VIDEO,
    VM_NOW_POST_TYPE_PLAYLIST,
    VM_NOW_POST_TYPE_ARTIST,
    VM_NOW_POST_TYPE_LINK,
    VM_NOW_POST_TYPE_UNKOWN = VM_NOW_POST_TYPE_DEFAULT
};

@interface VMNowPost : VMEntityBase

@property (nonatomic, readonly) VMNowPostType       type;
@property (nonatomic, readonly) NSInteger           postId;
@property (nonatomic, strong, readonly) NSString    *name;
@property (nonatomic, strong, readonly) NSString    *postDescription;
@property (nonatomic, strong, readonly) NSDate      *dateOfCreation;
@property (nonatomic, strong, readonly) NSDate      *datePublishFrom;
@property (nonatomic, strong, readonly) NSDate      *datePublishTo;
@property (nonatomic, readonly) NSInteger           publisherId;
@property (nonatomic, strong, readonly) NSString    *publisherName;
@property (nonatomic, strong, readonly) NSString    *contentId;
@property (nonatomic, readonly) NSInteger           groupId;
@property (nonatomic, strong, readonly) NSURL       *imageUrl;

@end


@interface VMNowPost(Video)

@property (nonatomic, strong, readonly) NSString    *isrc;
@property (nonatomic, strong, readonly) NSString    *title;
@property (nonatomic, readonly, getter = isPremiere) BOOL  premiere;
@property (nonatomic, readonly, getter = isLive) BOOL  live;

- (void)setupVideoPostData:(NSDictionary *)data;

@end

@interface VMNowPost(Playlist)

@property (nonatomic, strong, readonly) NSString    *playlistId;
@property (nonatomic, strong, readonly) NSArray     *videoList;
@property (nonatomic, strong, readonly) NSArray     *thumbnailUrls;

- (void)setupPlaylistData:(NSDictionary *)data;

@end

@interface VMNowPost(Artist)

@property (nonatomic, strong, readonly) NSArray     *artists;

- (void)setupArtistsData:(NSDictionary *)data;

@end

@interface VMNowPost(Link)

@property (nonatomic, strong, readonly) NSURL       *linkUrl;
@property (nonatomic, strong, readonly) NSString    *linkSource;

- (void)setupLinkPost:(NSDictionary *)data;

@end

