//
//  PTCLAnalytics_Protocol.swift
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2019/08/12.
//  Copyright © 2019 - 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

import Foundation

protocol PTCLAnalytics_Protocol: PTCLBase_Protocol
{
    init()
    init(nextAnalyticsWorker: PTCLAnalytics_Protocol)
    
    func nextAnalyticsWorker() -> PTCLAnalytics_Protocol?
    
    // MARK: - Identify
    func doIdentify(userId: String, traits: Dictionary<String, Any>?, options: Dictionary<String, Any>?)

    // MARK: - Track
    func doTrack(event: String, properties: Dictionary<String, Any>?, options: Dictionary<String, Any>?)

    // MARK: - Screen
    func doScreen(screenTitle: String, properties: Dictionary<String, Any>?, options: Dictionary<String, Any>?)

    // MARK: - Group
    func doGroup(groupId: String, traits: Dictionary<String, Any>?, options: Dictionary<String, Any>?)
}
