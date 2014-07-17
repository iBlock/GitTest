//
//  UDPAccess.h
//  MISP
//
//  Created by Mr.Cooriyou on 12-8-27.
//  Copyright (c) 2012年 wondersoft. All rights reserved.
//

#import "NetAccessBase.h"
#import "AsyncUdpSocket.h"
#import "CommandHelper.h"

@protocol UdpCommandResponseDelegate <NSObject>

-(void)commandResponse:(SystemCommand *)data;

@end

@interface UDPAccess : NetAccessBase<AsyncUdpSocketDelegate>
{
    AsyncUdpSocket* socket;
    id<UdpCommandResponseDelegate> delegate;
    NSString* ipAddress;
    UInt16 portNum;
}

@property (atomic, retain) AsyncUdpSocket *socket;
@property (atomic, assign) id<UdpCommandResponseDelegate> delegate;
@property (atomic,retain) NSString* ipAddress;
@property (atomic)UInt16 portNum;

-(void)commandRequest:(SystemCommand*)command;

@end
