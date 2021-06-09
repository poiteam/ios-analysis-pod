//
//  PLAnalysisConfig.h
//  PoilabsAnalysis
//
//  Created by ERCAN AYYILDIZ on 08/08/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLLocationManagerSettings.h"
#import "PLDataFilter.h"

@interface PLAnalysisConfig : NSObject


-(id)initWithData:(NSDictionary*)data;

@property(strong, nonatomic) NSString *messageUrl;

@property(assign, nonatomic) NSInteger messagingTimeInterval;

@property(strong, nonatomic) NSMutableArray *beaconRegionsMutableArray;

@property(strong, nonatomic) PLDataFilter *dataFilter;

@property(strong, nonatomic) PLLocationManagerSettings *locationManagerSettings;

@end
