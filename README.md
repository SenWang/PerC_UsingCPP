PerC SDK範例程式碼 : 使用 C++ (顯示彩色影像與深度影像)<br/>
參考文件 http://software.intel.com/sites/landingpage/perceptual_computing/documentation/html/index.html?docm_my_first_c_application.html

如果專案無法正常開啟，通常是因為找不到 .props 檔。請修改 .vcxproj 中的 <br/>
Project="..\\..\\..\\..\\..\Program Files (x86)\Intel\PCSDK\props\VS2010-12.Integration.MT.props" <br/>
變成<br/>
Project="$(PCSDK_DIR)\props\VS2010-12.Integration.MT.props" <br/>
(有兩處)

完成後重開專案即可編譯。如果無法 Start Debugging，請到專案的 Property Pages -> Configuration Properties -> Debugiing 看看是否有設定好

