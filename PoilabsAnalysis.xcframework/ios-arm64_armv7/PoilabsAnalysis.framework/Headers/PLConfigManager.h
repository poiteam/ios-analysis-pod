//
//  PLConfigManager.h
//  PoilabsAnalysis
//
//  Created by ERCAN AYYILDIZ on 08/08/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLConfig.h"
#import "PLError.h"

@interface PLConfigManager : NSObject

+ (instancetype)sharedInstance;


-(void)getReadyForTrackingWithCompletionHandler:(void (^)(PLError *error))completionHandler;

@property(strong, nonatomic) PLConfig *clientConfig;

@property(assign, nonatomic) BOOL bluetoothStatus;

@property(assign, nonatomic) CLAuthorizationStatus locationPermissionStatus;


@end
