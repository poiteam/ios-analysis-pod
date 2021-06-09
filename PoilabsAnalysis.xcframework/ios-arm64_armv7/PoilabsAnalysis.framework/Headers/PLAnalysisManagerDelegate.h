//
//  PLAnalysisManagerDelegate.h
//  PoilabsAnalysis
//
//  Created by ERCAN AYYILDIZ on 08/08/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLError.h"

@protocol PLAnalysisManagerDelegate  <NSObject>

@optional

-(void)analysisManagerDidFailWithPoiError:(PLError *)error;

-(void)analysisManagerResponseForBeaconMonitoring:(NSDictionary *)response;

@end
