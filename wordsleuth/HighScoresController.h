//
//  HighScoresController.h
//  wordsleuth
//
//  Created by Brian D. Elliott on 4/14/11.
//  Copyright 2011 Sparkle Software. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DebugGestureView.h"
#import "GameState.h"

@interface HighScoresController : UIViewController <DebugViewDelegate> {
    
    GameState *gameState;
    
    IBOutlet UITableView *highScoresTableView;
    IBOutlet UILabel *yourScoreLabel;
    UILabel *timeLeftLabel;

    NSArray *scores;
    NSTimer *timer;
    UIButton *playAgainButton;
    
    BOOL bragsEnabled;
    UIAlertView *facebookBragPrompt;
    IBOutlet UILabel *bragLabel;
    UIButton *facebookBragButton;
    NSDate *lastFacebookBragDate;
    
    // DEBUG stuff
    BOOL debugTimer;
    NSDate *debugTimerExpiration;  
}

@property (nonatomic, retain) GameState *gameState;

@property (nonatomic, retain) IBOutlet UITableView *highScoresTableView;
@property (nonatomic, retain) IBOutlet UILabel *timeLeftLabel;
@property (nonatomic, retain) IBOutlet UILabel *yourScoreLabel;

@property (nonatomic, retain) NSTimer *timer;
@property (nonatomic, retain) IBOutlet UIButton *playAgainButton;
@property (nonatomic, assign) int lastPlayedNumGuesses;

@property (nonatomic, retain) DebugGestureView *debugGestureView;

@property (nonatomic, assign) BOOL bragsEnabled;
@property (nonatomic, retain) IBOutlet UILabel *bragLabel;
@property (nonatomic, retain) UIAlertView *facebookBragPrompt;
@property (nonatomic, retain) IBOutlet UIButton *facebookBragButton;

- (id)initWithGameState:(GameState *)gState;

- (void)enableTimer;
- (NSMutableString *) formatTimeLeft:(int) secsuntilmidnight;
- (int)getSecondsUntilNextPlay;
- (void)enableNextPlay;
- (void)updateTimeLeft;
- (void)updateTimeLeftLabel:(int)secondsUntilNextPlay;

- (IBAction)pressedPlayAgain:(id)sender;
- (void)togglePlayAgainButton:(BOOL)enabled;
- (void) loadBestScores;

- (void)showUserScore;

- (IBAction)facebookBragPressed:(id)sender;
- (BOOL)braggedToday;

+ (UIColor *) highlightColor;

- (void)cancelLocalNotification;
- (void)scheduleLocalNotification;

@end
