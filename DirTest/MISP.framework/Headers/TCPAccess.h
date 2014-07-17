//
//  TCPAccess.h
//  MISP
//
//  Created by Mr.Cooriyou on 12-8-27.
//  Copyright (c) 2012年 wondersoft. All rights reserved.
//

#import "NetAccessBase.h"
#import "AsyncSocket.h"
#import "CommandHelper.h"


@protocol CommandResponseDelegate <NSObject>

-(void)commandResponse:(SystemCommand *)data;

@end


@interface TCPAccess : NetAccessBase<AsyncSocketDelegate>
{
    AsyncSocket *socket;
    id<CommandResponseDelegate> delegate;
    NSString* ipAddress;
    UInt16 portNum;
}

@property (atomic, retain) AsyncSocket *socket;
@property (atomic, assign) id<CommandResponseDelegate> delegate;
@property (atomic,retain) NSString* ipAddress;
@property (atomic)UInt16 portNum;

-(void)setResponseDelegate:(id<CommandResponseDelegate>)responseDelegate;

-(void)commandRequest:(SystemCommand*)command;

-(void)disconnect;

@end
