//
//  AdminCell.swift
//  InventorInspiration
//
//  Created by Isaac Albets Ramonet on 05/04/2017.
//  Copyright © 2017 com.IsaacRamonet. All rights reserved.
//

import UIKit

class AdminCell: UITableViewCell {

    // MARK: Properties
    @IBOutlet weak var title: UILabel!
    @IBOutlet weak var switcher: UISwitch!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }
    
    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)
        switcher.isOn ? true : false
    }


}
