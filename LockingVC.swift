

//
//  LockingkVC.swift
//  InventorInspiration
//
//  Created by Isaac Albets Ramonet on 05/04/2017.
//  Copyright © 2017 com.IsaacRamonet. All rights reserved.
//

import UIKit
import LocalAuthentication

class LockingViewController: UIViewController {
    
    // MARK: Properties
    @IBOutlet weak var biometricLogin: UIButton!
    @IBOutlet weak var lockImage: UIImageView!
    @IBOutlet weak var passwordField: UITextField!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Do any additional setup after loading the view.
    }
    
    @IBAction func loginByForm() {
        
        let authenticationContext = LAContext()
        var error: NSError?
        
        // Check if the device has a fingerprintSensor
        guard authenticationContext.canEvaluatePolicy(.deviceOwnerAuthenticationWithBiometrics, error: &error) else {
            return
        }
        
        authenticationContext.evaluatePolicy(.deviceOwnerAuthenticationWithBiometrics, localizedReason: "Unlock InventorInspiration") { [unowned self] (success, error) in
            
            if success {
                // fingerprint recognized
                self.allowUserToGetIn()
            } else {
                // check if there is an error
                if let error = error {
                    // should be error.code
                    let message = self.errorMessageForLAErrorCode(errorCode: error as! Int)
                    self.showAlertViewAfterEvaluatingPolicyWithMessage(message: "\(message)")
                }
                
            }
            
        }
    }
    
    
    func showAlertIfNoBiometricSensorDetected() {
        showAlertWithTitle(title: "Error", message: "Your device does not have a TouchID sensor.")
    }
    
    func showAlertViewAfterEvaluatingPolicyWithMessage(message: String) {
        showAlertWithTitle(title: "Error", message: message)
    }
    
    
    func showAlertWithTitle(title: String, message: String) {
        
        let alert = UIAlertController(title: title, message: message, preferredStyle: .alert)
        let okButton = UIAlertAction(title: "Ok", style: UIAlertActionStyle.default, handler: nil)
        
        alert.addAction(okButton)
        
        DispatchQueue.main.async {
            self.present(alert, animated: true, completion: nil)
        }
        
    }
    
    
    func errorMessageForLAErrorCode(errorCode: Int ) -> String {
        
        var message = ""
        
        // TODO: do something with the string I get so I can get the numbers
        
        switch errorCode {
            
        case LAError.appCancel.rawValue:
            message = "Authentication was cancelled by application"
            
        case LAError.authenticationFailed.rawValue:
            message = "The user failed to provide valid credentials"
            
        case LAError.invalidContext.rawValue:
            message = "The context is invalid"
            
        case LAError.passcodeNotSet.rawValue:
            message = "Passcode is not set on the device"
            
        case LAError.systemCancel.rawValue:
            message = "Authentication was cancelled by the system"
            
        case LAError.touchIDLockout.rawValue:
            message = "Too many failed attempts."
            
        case LAError.touchIDNotAvailable.rawValue:
            message = "TouchID is not available on the device"
            
        case LAError.userCancel.rawValue:
            message = "The user did cancel"
            
        case LAError.userFallback.rawValue:
            message = "The user chose to use the fallback"
            
        default:
            message = "Did not find error code on LAError object"
            
        }
        
        return message
        
    }
    
    /*
     // MARK: - Navigation
     
     // In a storyboard-based application, you will often want to do a little preparation before navigation
     override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
     // Get the new view controller using segue.destinationViewController.
     // Pass the selected object to the new view controller.
     }
     */
    
    func allowUserToGetIn() {
        if let loggedIn = storyboard?.instantiateViewController(withIdentifier: "") {
            DispatchQueue.main.async {
                self.navigationController?.pushViewController(loggedIn, animated: true)
            }
        }
    }
}
