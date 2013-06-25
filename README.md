PerC SDK範例程式碼 : 使用 C++
參考文件 http://software.intel.com/sites/landingpage/perceptual_computing/documentation/html/index.html?docm_my_first_c_application.html

如果專案無法正常開啟，通常是因為找不到 .props 檔。請修改 .vcxproj 中的
<Import Project="..\..\..\..\..\Program Files (x86)\Intel\PCSDK\props\VS2010-12.Integration.MT.props" />
變成
<Import Project="$(PCSDK_DIR)\props\VS2010-12.Integration.MT.props" />
(有兩處)

