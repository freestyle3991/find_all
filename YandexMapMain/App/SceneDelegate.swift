import UIKit

class SceneDelegate: UIResponder, UIWindowSceneDelegate {
    
    
    var window: UIWindow?
    var navigationController: UINavigationController!
    var homeViewController: TabbarController!
    var locationViewModel = MapViewModel()

    
    func scene(_ scene: UIScene, willConnectTo session: UISceneSession, options connectionOptions: UIScene.ConnectionOptions) {
        guard let windowScene = (scene as? UIWindowScene) else { return }
        
        let window = UIWindow(windowScene: windowScene)
        window.overrideUserInterfaceStyle = .light
        
        locationViewModel.requestLocationAccess()
        
        let tabBarController = TabbarController()
        self.homeViewController = tabBarController
        window.rootViewController = self.homeViewController
        window.makeKeyAndVisible()
        self.window = window
    }
}
