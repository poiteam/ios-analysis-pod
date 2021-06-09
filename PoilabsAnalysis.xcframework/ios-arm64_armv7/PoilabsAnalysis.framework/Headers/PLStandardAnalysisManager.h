//
//  PLStandardAnalysisManager.h
//  PoilabsAnalysis
//
//  Created by ERCAN AYYILDIZ on 08/08/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLAnalysisManagerDelegate.h"

@interface PLStandardAnalysisManager : NSObject

+(instancetype)sharedInstance;

@property(strong, nonatomic) id<PLAnalysisManagerDelegate> delegate;

-(void)startBeaconMonitoring;

-(void)stopBeaconMonitoring;


-(void)bluetoothStatusChanged:(BOOL)bluetoothStatus;

@end
