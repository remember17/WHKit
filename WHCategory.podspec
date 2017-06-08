    Pod::Spec.new do |s|  
      
      s.name         = "WHCategory"  
      s.version      = "1.0.2"  
      s.summary      = "Make development easier."  
      s.homepage     = "https://github.com/remember17/WHCategory"  
      s.license      = "MIT"  
      s.author       = { "wuhao" => "503007958@qq.com" }  
      s.platform     = :ios, "7.0"  
      s.source       = { :git => "https://github.com/remember17/WHCategory.git", :tag => s.version }  
      s.source_files  = "WHCategory", "WHCategory/*.{h,m}"  
      s.framework  = "UIKit"  
      s.requires_arc = true   
      
    end  