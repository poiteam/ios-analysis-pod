//
//  PLLocationManager.h
//  PoilabsAnalysis
//
//  Created by ERCAN AYYILDIZ on 08/08/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "PLLocationManagerSettings.h"
#import "PLLocationManagerDelegate.h"

typedef NS_ENUM(NSInteger, PLLocationManagerWorkingStatus)
{
    PLLocationManagerWorkingStatusNone,
    PLLocationManagerWorkingStatusStopped,
    PLLocationManagerWorkingStatusAlways,
    PLLocationManagerWorkingStatusWhenInUse
    
};
@interface PLLocationManager : NSObject<CLLocationManagerDelegate>

- (id)initWithRegions:(NSArray *)regions;

@property(assign, nonatomic) PLLocationManagerWorkingStatus workingStatus;

@property(strong, nonatomic) CLLocationManager *coreLocationManager;

@property(strong, nonatomic) PLLocationManagerSettings *settings;

@property(assign, nonatomic) CLAuthorizationStatus currentAuthorizationStatus;

@property(strong, nonatomic) NSArray *regions;

@property (strong, nonatomic) id<PLLocationManagerDelegate> delegate;

@property (assign, nonatomic) BOOL applicationDidBecomeActive;

-(void)requestAlwaysAuthorization;

-(void)requestWhenInUseAuthorization;

-(void)startBeaconTracking;


@end
