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
#import "PHAnimationDriver.h"
#import "PHDriver.h"
#import "PHDegrader.h"
#import "PHSpritesheet.h"

typedef NSArray* (^PHAdditionalAnimationBlock)();

/**
 * The PHAnimation class exposes the fundamental tools and API for creating
 * Pixel Heart animations.
 */
@interface PHAnimation : NSObject

// Convenience method for creating an animation object.
+ (id)animation;

@property (nonatomic, strong) PHDegrader* bassDegrader;
@property (nonatomic, strong) PHDegrader* hihatDegrader;
@property (nonatomic, strong) PHDegrader* vocalDegrader;
@property (nonatomic, strong) PHDegrader* snareDegrader;
@property (nonatomic, readonly) NSTimeInterval secondsSinceLastTick; // 0 on first run.
@property (nonatomic, readonly) NSTimeInterval lastTick; // 0 on first run

// The driver exposes a number of pre-calculated values that all animations
// share.
@property (nonatomic, strong) PHAnimationDriver* driver;

// Subclasses must implement this method to render their frames.
// This method will be called frequently.
- (void)renderBitmapInContext:(CGContextRef)cx size:(CGSize)size;

// Subclasses should call super.
- (void)bitmapWillStartRendering;
- (void)bitmapDidFinishRendering;

- (NSString *)tooltipName;
- (BOOL)isPipeAnimation; // Default returns NO

+ (NSArray *)allAnimations;

+ (void)setAdditionalAnimationCreator:(PHAdditionalAnimationBlock)block;

@end
