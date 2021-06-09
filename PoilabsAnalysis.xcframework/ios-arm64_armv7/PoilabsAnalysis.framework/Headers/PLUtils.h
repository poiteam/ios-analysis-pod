//
//  PLUtils.h
//  PoilabsAnalysis
//
//  Created by ERCAN AYYILDIZ on 08/08/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLAFHTTPSessionManager.h"


@interface PLUtils : NSObject

+(void)logDebugInformations:(NSString *)string priority:(int)priorityLevel inManagerType:(NSString *)comingType;


+(PLAFHTTPSessionManager *)getJsonSessionManager;
@end
