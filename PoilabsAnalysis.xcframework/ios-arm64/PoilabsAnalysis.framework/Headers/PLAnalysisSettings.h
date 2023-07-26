//
//  PLAnalysisSettings.h
//  PoilabsAnalysis
//
//  Created by ERCAN AYYILDIZ on 08/08/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PLAnalysisSettings : NSObject

+(instancetype)sharedInstance;

//Before Config Ready
@property(strong, nonatomic) NSString *applicationId;

@property(strong, nonatomic) NSString *applicationSecret;

@property(strong, nonatomic) NSString *analysisUniqueIdentifier;

@property(assign, nonatomic) BOOL operationSystemBluetoothAlertAvailable;


// Customer Setting Before Start Monitoring - Config Manager initialize



@property(strong, nonatomic) NSNumber *backgroundModeIsActive;

@property(strong, nonatomic) NSNumber *standardModeIsActive;

@property(strong, nonatomic) NSNumber *suspendedModeIsActive;

@property(strong, nonatomic) NSNumber *idfaIsActive;

-(void)closeAllActions;

// optional; if you want to get additional data with your identifier, set this dictionary this will be send to server
// it will not be saved to UserDefault , to get this data you should set this value before startBeaconMonitoring both standard and suspended
@property(strong, nonatomic) NSDictionary *customUserData;
@end
