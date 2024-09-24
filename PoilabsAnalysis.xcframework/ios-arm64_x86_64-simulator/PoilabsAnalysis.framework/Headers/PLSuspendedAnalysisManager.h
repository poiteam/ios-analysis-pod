//
//  PLSuspendedAnalysisManager.h
//  PoilabsAnalysis
//
//  Created by ERCAN AYYILDIZ on 08/08/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLAnalysisManagerDelegate.h"

@interface PLSuspendedAnalysisManager : NSObject

+ (instancetype)sharedInstance;

@property(strong, nonatomic) id<PLAnalysisManagerDelegate> delegate;

-(void)startBeaconMonitoring;

-(void)stopBeaconMonitoring;

@end
