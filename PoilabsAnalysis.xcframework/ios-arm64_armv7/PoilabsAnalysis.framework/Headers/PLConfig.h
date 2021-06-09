//
//  PLConfig.h
//  PoilabsAnalysis
//
//  Created by ERCAN AYYILDIZ on 08/08/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLAnalysisConfig.h"

@interface PLConfig : NSObject

-(id)initWithData:(NSDictionary*)data;

@property(strong, nonatomic) PLAnalysisConfig *standardAnalysisConfig;

@property(strong, nonatomic) PLAnalysisConfig *suspendedAnalysisConfig;


@end
