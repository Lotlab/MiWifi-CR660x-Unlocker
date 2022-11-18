# MiWifi CR660x 解锁工具

这是一个基于ESP32的，给CR660x提供解锁用Wifi的解锁工具。参考[恩山 keke1023](https://www.right.com.cn/forum/thread-5379258-1-1.html)的思路实现。

## 使用方法

1. 编译并烧录固件。使用ESP-IDF可以很方便的编译并烧录固件，详见ESP-IDF官方文档。[点击这里](https://github.com/Lotlab/MiWifi-CR660x-Unlocker/releases)可以下载已经编译好的固件。
2. 搜索 wifi。你应该可以搜索到一个名为 `miwifi_unlocker` 的 wifi，其密码为 `password`。
3. 如果你想使用内置的帮助页面作为辅助刷机的工具，请将你的电脑连接到这个wifi，并尝试访问 `169.254.31.1`。因为这个固件关闭了DHCP，你需要手动指定IP地址 `169.254.31.3`，网关 `169.254.31.1`和子网掩码 `255.255.255.0`。
4. 跟着帮助页面或者是其他刷机教程做即可。
