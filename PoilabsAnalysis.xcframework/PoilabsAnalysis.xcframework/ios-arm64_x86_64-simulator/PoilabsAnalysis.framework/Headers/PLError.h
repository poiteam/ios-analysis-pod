//
//  PLError.h
//  PoilabsAnalysis
//
//  Created by ERCAN AYYILDIZ on 08/08/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PLErrorCode)
{
    PLErrorCodeDefault,
    PLErrorCodePropertyList,
    PLErrorCodeClientConfig,
    PLErrorCodeAnalysisManagerInformation,
    PLErrorCodeBeaconRequestFail
    
};






@interface PLError : NSObject

@property(assign, nonatomic) PLErrorCode errorCode;

@property(strong, nonatomic) NSString *errorDescription;
@end
