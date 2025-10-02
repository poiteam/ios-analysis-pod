//
//  PLLocationManagerDelegate.h
//  PoilabsAnalysis
//
//  Created by ERCAN AYYILDIZ on 08/08/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLError.h"

@class PLLocationManager;

@protocol PLLocationManagerDelegate  <NSObject>

@optional

-(void)locationManager:(PLLocationManager *)manager didRangePoiBeacons:(NSArray *)beacons;

-(void)locationManager:(PLLocationManager *)manager didFailWithPoiError:(PLError *)error;

@end
