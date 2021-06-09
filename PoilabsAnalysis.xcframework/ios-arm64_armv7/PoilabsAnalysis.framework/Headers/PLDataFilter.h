//
//  PLDataFilter.h
//  PoilabsAnalysis
//
//  Created by ERCAN AYYILDIZ on 08/08/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PLDataSelectionMode)
{
    PLDataSelectionDefault = 0, // Best RSSI
    PLDataSelectionBestRSSI,  //1
    PLDataSelectionUniqueBeacon,  // 2
};


@interface PLDataFilter : NSObject

-(id) initWithData:(NSDictionary *)data;

@property(assign, nonatomic) NSTimeInterval windowingTimeInterval;

@property(assign, nonatomic) NSTimeInterval windowingTotalSignalSize;

@property(assign, nonatomic) NSInteger maxScannedPoiCount;

@property(assign, nonatomic) NSInteger dataSelectionMode;

@property(strong, nonatomic) NSMutableArray *beaconFiltersMutableArray;

@end
