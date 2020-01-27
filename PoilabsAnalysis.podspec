Pod::Spec.new do |s|  
    s.name              = 'PoilabsAnalysis'
    s.version           = '3.7.8'
    s.summary           = 'Poilabs Analysis'
    s.homepage          = 'https://www.poilabs.com'

    s.author            = { 'Emre Kuru' => 'emre@poilabs.com' }
    s.license           = { :type => 'MIT', :file => 'LICENSE' }

    s.platform          = :ios
    s.source            = { :http => 'https://poigeneral.blob.core.windows.net/sdk/YourFrameWork.zip?sp=r&st=2019-10-30T12:23:07Z&se=2019-12-31T20:23:07Z&spr=https&sv=2019-02-02&sr=b&sig=a6D131sUSUamGpLxzzb2nV3jIOkJpC6hMUeKIrwwzmU%3D' }
    #s.source_files      = "add your header files which would be public"
    s.ios.deployment_target = '8.0'
    s.ios.vendored_frameworks = 'PoilabsAnalysis.framework'
end