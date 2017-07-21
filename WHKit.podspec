    Pod::Spec.new do |s|  
      
      s.name         = "WHKit" 
      s.version      = "1.3.0"  
      s.summary      = "Make development easier."  
      s.homepage     = "https://github.com/remember17/WHKit"  
      s.license      = "MIT"  
      s.author       = { "wuhao" => "503007958@qq.com" }  
      s.platform     = :ios, "7.0"  
      s.source       = { :git => "https://github.com/remember17/WHKit.git", :tag => s.version }  
      s.source_files  = "WHKit", "WHKit/*.{h,m}"  
      s.framework  = "UIKit"  
      s.requires_arc = true   
      
    end  