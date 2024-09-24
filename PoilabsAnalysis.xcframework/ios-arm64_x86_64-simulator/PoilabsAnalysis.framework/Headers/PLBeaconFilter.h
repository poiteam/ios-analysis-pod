//
//  PLBeaconFilter.h
//  PoilabsAnalysis
//
//  Created by ERCAN AYYILDIZ on 08/08/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PLBeaconFilter : NSObject

-(id) initWithData:(NSDictionary *)data;

@property(assign, nonatomic) NSInteger majorId;

@property(strong, nonatomic) NSUUID *serviceUUID;

@property(assign, nonatomic) NSInteger rssi;

@end
