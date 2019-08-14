//
//  __PTCLBase_Protocol.swift
//  DoubleNode Core
//
//  Created by Darren Ehlers on 2019/08/12.
//  Copyright © 2019 - 2016 Darren Ehlers and DoubleNode, LLC. All rights reserved.
//

import Foundation

typealias PTCLProgressBlock = (Int, Int, Float, String) -> Void

protocol PTCLBase_Protocol: class
{
    func configure()
    
    func enableOption(option: String)
    func disableOption(option: String)
}
