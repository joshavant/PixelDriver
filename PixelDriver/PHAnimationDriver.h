//
// Copyright 2012 Jeff Verkoeyen
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>

@interface PHAnimationDriver : NSObject

// Raw values
@property (nonatomic, readonly) float* spectrum;
@property (nonatomic, readonly) NSInteger numberOfSpectrumValues;

// Processed values
@property (nonatomic, readonly) CGFloat subBassAmplitude;
@property (nonatomic, readonly) CGFloat hihatAmplitude;
@property (nonatomic, readonly) CGFloat vocalAmplitude;

@end

@interface PHAnimationDriver()

- (void)setSpectrum:(float *)spectrum numberOfValues:(NSInteger)numberOfValues;

@end
