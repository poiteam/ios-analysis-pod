Pod::Spec.new do |s|

# 1
s.platform = :ios
s.ios.deployment_target = '9.0'
s.name = "PoilabsAnalysis"
s.summary = "PoilabsAnalysis"
#s.requires_arc = true

#2
s.version = "3.8.28"

# 3
s.license = { :type => "Proprietary", :file => "LICENSE" }

# 4 - Replace with your name and e-mail address
s.author = { "Burak Dönmez" => "burak@poilabs.com" }

# 5 - Replace this URL with your own GitHub page's URL (from the address bar)
s.homepage = "https://github.com/poiteam/ios-analysis-pod.git"

# 6 - Replace this URL with your own Git URL from "Quick Setup"
s.source = { :git => "https://emrekuru@github.com/poiteam/ios-analysis-pod.git",
             :tag => "#{s.version}" }

s.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }


s.ios.vendored_frameworks = 'PoilabsAnalysis.xcframework'
end
