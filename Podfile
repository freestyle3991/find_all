
source 'https://github.com/CocoaPods/Specs.git'
# Uncomment the next line to define a global platform for your project
platform :ios, '15.0'

target 'YandexMapLUDITO' do
  # Comment the next line if you don't want to use dynamic frameworks
  use_frameworks!
  
post_install do |installer|
    installer.pods_project.build_configurations.each do |config|
#      config.build_settings["EXCLUDED_ARCHS[sdk=iphonesimulator*]"] = "arm64"
      config.build_settings['ENABLE_BITCODE'] = 'NO'
    end
    installer.generated_projects.each do |project|
      project.targets.each do |target|
        target.build_configurations.each do |config|
          config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '15.0'
        end
      end
    end
  end
  
  pod 'YandexMapsMobile', '4.4.1-full'
  pod 'SnapKit'

  
end
