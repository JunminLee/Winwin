S/W Version Information
Model: Ref.Device-PQ
Tizen-Version: 2.2.1
Build-Number: Tizen_Ref.Device-PQ_20131118.1124
Build-Date: 2013.11.18 11:24:59

Crash Information
Process Name: TizenProject
PID: 20447
Date: 2014-08-15 02:44:25(GMT+0900)
Executable File Path: /opt/apps/X4TuAhqX38/bin/TizenProject
This process is multi-thread process
pid=20447 tid=20447
Signal: 11
      (SIGSEGV)
      si_code: 1
      address not mapped to object
      si_addr = 0x58

Register Information
r0   = 0xbeffc8a0, r1   = 0x00000050
r2   = 0xb6637330, r3   = 0x00007cd4
r4   = 0xbeffc8a0, r5   = 0xb6fb0d70
r6   = 0x00000050, r7   = 0xaae3c070
r8   = 0xbeffcc0c, r9   = 0xbeffcef0
r10  = 0xb6fb0d70, fp   = 0xbeffc900
ip   = 0xb6fb71d0, sp   = 0xbeffc840
lr   = 0xb6c7a499, pc   = 0xb6c7a49c
cpsr = 0x88000030

Memory Information
MemTotal:   797320 KB
MemFree:     12468 KB
Buffers:      7228 KB
Cached:     239332 KB
VmPeak:     279416 KB
VmSize:     217328 KB
VmLck:           0 KB
VmHWM:      105664 KB
VmRSS:      105664 KB
VmData:     134668 KB
VmStk:         136 KB
VmExe:         420 KB
VmLib:       71712 KB
VmPTE:         228 KB
VmSwap:          0 KB

Maps Information
2a000000 2a069000 r-xp /opt/usr/apps/X4TuAhqX38/bin/TizenProject.exe
2a071000 2a076000 rwxp /opt/usr/apps/X4TuAhqX38/bin/TizenProject.exe
2a076000 2aa9d000 rwxp [heap]
a6aa4000 a6de4000 rwxs /dev/mali
a7412000 a7796000 rwxs /dev/ump
a92ad000 a93cc000 r-xp /usr/lib/locale/locale-archive
a93cc000 a944c000 rwxs /dev/mali
a944c000 a94cc000 rwxs /dev/mali
a94cc000 a95cc000 rwxs /dev/mali
a9980000 a9a80000 rwxs /dev/mali
a9a80000 a9b80000 rwxs /dev/mali
a9b80000 a9c80000 rwxs /dev/mali
a9c80000 aa000000 rwxs /dev/mali
aa100000 aa200000 rwxs /dev/mali
ac858000 ac9d8000 rwxs /dev/mali
ac9d8000 acbd8000 rwxs /dev/mali
acbd8000 acdd8000 rwxs /dev/mali
ad16c000 ad1ac000 rwxs /dev/mali
ad1ac000 ad530000 rwxs /dev/ump
ad530000 ad570000 rwxs /dev/mali
ad570000 ad8f4000 rwxs /dev/ump
ad8f4000 ad934000 rwxs /dev/mali
ad934000 adcb8000 rwxs /dev/ump
adcb8000 ae03c000 rwxs /dev/ump
ae03c000 ae3c0000 rwxs /dev/ump
ae3c0000 ae744000 rwxs /dev/ump
ae965000 ae9e5000 rwxs /dev/mali
ae9e5000 ae9f6000 r-xp /usr/lib/scim-1.0/1.4.0/IMEngine/socket.so
ae9fe000 ae9ff000 rwxp /usr/lib/scim-1.0/1.4.0/IMEngine/socket.so
ae9ff000 aea04000 r-xp /usr/lib/libhaptic-module.so
aea0b000 aea0c000 rwxp /usr/lib/libhaptic-module.so
aea0c000 aea8c000 rwxs /dev/mali
aea8c000 aeacc000 rwxs /dev/mali
aeacc000 aee4c000 rwxs /dev/mali
aef2e000 aefae000 rwxs /dev/mali
af178000 af4fc000 rwxs /dev/ump
af4fc000 af53c000 rwxs /dev/mali
af53c000 af57c000 rwxs /dev/mali
af57c000 af8fc000 rwxs /dev/mali
afc62000 afce2000 rwxs /dev/mali
afce2000 afd62000 rwxs /dev/mali
afd62000 afde2000 rwxs /dev/mali
afec4000 afeef000 rwxs /dev/shm/elm_indicator_portrait-0-1407702608.2675.1044951031
afeef000 aff3a000 rwxs /dev/shm/elm_indicator_landscape-0-1407702608.2675.1394747586
aff3a000 aff65000 rwxs /dev/shm/elm_indicator_portrait-0-1407702608.2675.1044951031
aff65000 affb0000 rwxs /dev/shm/elm_indicator_landscape-0-1407702608.2675.1394747586
b0165000 b0167000 r-xp /usr/lib/evas/modules/loaders/png/linux-gnueabi-armv7l-1.7.99/module.so
b016e000 b016f000 rwxp /usr/lib/evas/modules/loaders/png/linux-gnueabi-armv7l-1.7.99/module.so
b016f000 b01af000 rwxs /dev/mali
b01af000 b022f000 rwxs /dev/mali
b022f000 b030a000 r-xp /usr/share/fallback_fonts/TizenSansKoreanRegular.ttf
b030a000 b032f000 r-xp /usr/share/fonts/TizenSansRegular.ttf
b032f000 b0337000 r-xs /var/cache/fontconfig/cdc77cde135ce87b641818a103cc9edb-le32d8.cache-3
b033b000 b033f000 r-xp /usr/share/locale/ko_KR/LC_MESSAGES/scim.mo
b033f000 b0344000 r-xp /usr/lib/scim-1.0/1.4.0/Config/socket.so
b034b000 b034c000 rwxp /usr/lib/scim-1.0/1.4.0/Config/socket.so
b034c000 b034f000 r-xp /usr/share/locale/ko_KR/LC_MESSAGES/osp.mo
b034f000 b038f000 rwxs /dev/mali
b038f000 b03cf000 rwxs /dev/mali
b03d2000 b03f7000 r-xp /usr/share/fonts/TizenSansMedium.ttf
b03f7000 b0437000 rwxs /dev/mali
b0437000 b0477000 rwxs /dev/mali
b0477000 b04b7000 rwxs /dev/mali
b04b7000 b04f7000 rwxs /dev/mali
b06bb000 b06bc000 r-xs /opt/home/app/.cache/evas_gl_common_caches/ARM::OpenGL
b06bc000 b06bd000 rwxs /dev/ump
b06bd000 b06c3000 r-xs /opt/home/app/.cache/evas_gl_common_caches/ARM::OpenGL
b06c3000 b0703000 rwxs /dev/mali
b0703000 b0743000 rwxs /dev/mali
b1f43000 b1f8e000 r-xp /usr/lib/libGLESv1_CM.so.1.1
b1f96000 b1f97000 rwxp /usr/lib/libGLESv1_CM.so.1.1
b1f97000 b1fa1000 r-xp /usr/lib/evas/modules/engines/software_generic/linux-gnueabi-armv7l-1.7.99/module.so
b1fa8000 b1fa9000 rwxp /usr/lib/evas/modules/engines/software_generic/linux-gnueabi-armv7l-1.7.99/module.so
b1fa9000 b1fd1000 r-xp /usr/lib/evas/modules/engines/gl_x11/linux-gnueabi-armv7l-1.7.99/module.so
b1fd1000 b1fd2000 rwxp /usr/lib/evas/modules/engines/gl_x11/linux-gnueabi-armv7l-1.7.99/module.so
b1fd5000 b1ff9000 r-xp /usr/share/locale/ko/LC_MESSAGES/libc.mo
b1ff9000 b2003000 r-xp /lib/libnss_files-2.13.so
b200a000 b200b000 r-xp /lib/libnss_files-2.13.so
b200b000 b200c000 rwxp /lib/libnss_files-2.13.so
b200c000 b2015000 r-xp /lib/libnss_nis-2.13.so
b201c000 b201d000 r-xp /lib/libnss_nis-2.13.so
b201d000 b201e000 rwxp /lib/libnss_nis-2.13.so
b201e000 b202f000 r-xp /lib/libnsl-2.13.so
b2036000 b2037000 r-xp /lib/libnsl-2.13.so
b2037000 b2038000 rwxp /lib/libnsl-2.13.so
b203a000 b2040000 r-xp /lib/libnss_compat-2.13.so
b2047000 b2048000 r-xp /lib/libnss_compat-2.13.so
b2048000 b2049000 rwxp /lib/libnss_compat-2.13.so
b2049000 b2114000 r-xp /usr/lib/libscim-1.0.so.8.2.3
b211c000 b212a000 rwxp /usr/lib/libscim-1.0.so.8.2.3
b212a000 b212d000 r-xp /usr/lib/bufmgr/libtbm_exynos4412.so.0.0.0
b2134000 b2135000 rwxp /usr/lib/bufmgr/libtbm_exynos4412.so.0.0.0
b2135000 b213c000 r-xs /usr/lib/gconv/gconv-modules.cache
b213c000 b2160000 r-xp /usr/lib/ecore/immodules/libisf-imf-module.so
b2167000 b2169000 rwxp /usr/lib/ecore/immodules/libisf-imf-module.so
b2169000 b2369000 r-xp /usr/lib/locale/locale-archive
b2372000 b237e000 r-xp /usr/lib/libtzsvc.so.0.0.1
b2386000 b2387000 rwxp /usr/lib/libtzsvc.so.0.0.1
b238b000 b23b1000 r-xp /usr/lib/libzmq.so.3.0.0
b23b8000 b23bb000 rwxp /usr/lib/libzmq.so.3.0.0
b23bc000 b23c5000 r-xp /usr/lib/libpims-ipc.so.0.0.30
b23cc000 b23cd000 rwxp /usr/lib/libpims-ipc.so.0.0.30
b23cd000 b23cf000 r-xp /usr/lib/libemail-network.so.1.1.0
b23d6000 b23d7000 rwxp /usr/lib/libemail-network.so.1.1.0
b23d7000 b23f0000 r-xp /usr/lib/libaccounts-svc.so.0.2.66
b23f7000 b23f8000 rwxp /usr/lib/libaccounts-svc.so.0.2.66
b23f9000 b24a3000 r-xp /usr/lib/libuw-imap-toolkit.so.0.0.0
b24ab000 b24b1000 rwxp /usr/lib/libuw-imap-toolkit.so.0.0.0
b24b1000 b24b5000 r-xp /usr/lib/libss-client.so.1.0.0
b24bc000 b24bd000 rwxp /usr/lib/libss-client.so.1.0.0
b24bd000 b24bf000 r-xp /usr/lib/libcamsrcjpegenc.so.0.0.0
b24c6000 b24c7000 rwxp /usr/lib/libcamsrcjpegenc.so.0.0.0
b24c8000 b2502000 r-xp /usr/lib/libpulsecommon-0.9.23.so
b250a000 b250b000 rwxp /usr/lib/libpulsecommon-0.9.23.so
b250b000 b250f000 r-xp /usr/lib/libmmfsoundcommon.so.0.0.0
b2516000 b2517000 rwxp /usr/lib/libmmfsoundcommon.so.0.0.0
b2517000 b251a000 r-xp /lib/libattr.so.1.1.0
b2521000 b2522000 rwxp /lib/libattr.so.1.1.0
b2522000 b2525000 r-xp /usr/lib/libsyspopup_caller.so.0.1.0
b252c000 b252d000 rwxp /usr/lib/libsyspopup_caller.so.0.1.0
b252e000 b2537000 r-xp /usr/lib/libgstapp-0.10.so.0.25.0
b253e000 b253f000 rwxp /usr/lib/libgstapp-0.10.so.0.25.0
b253f000 b254c000 r-xp /usr/lib/libgstinterfaces-0.10.so.0.25.0
b2554000 b2555000 rwxp /usr/lib/libgstinterfaces-0.10.so.0.25.0
b2555000 b255b000 r-xp /usr/lib/libUMP.so
b2562000 b2563000 rwxp /usr/lib/libUMP.so
b2564000 b2566000 r-xp /usr/lib/libXau.so.6.0.0
b256d000 b256e000 rwxp /usr/lib/libXau.so.6.0.0
b256e000 b257e000 r-xp /lib/libresolv-2.13.so
b257e000 b257f000 r-xp /lib/libresolv-2.13.so
b257f000 b2580000 rwxp /lib/libresolv-2.13.so
b2582000 b2587000 r-xp /usr/lib/libffi.so.5.0.10
b258e000 b258f000 rwxp /usr/lib/libffi.so.5.0.10
b258f000 b2599000 r-xp /usr/lib/libethumb.so.1.7.99
b25a0000 b25a1000 rwxp /usr/lib/libethumb.so.1.7.99
b25a2000 b25e6000 r-xp /usr/lib/libsndfile.so.1.0.25
b25ee000 b25f0000 rwxp /usr/lib/libsndfile.so.1.0.25
b25f4000 b25f6000 r-xp /usr/lib/libctxdata.so.0.0.0
b25fd000 b25fe000 rwxp /usr/lib/libctxdata.so.0.0.0
b25fe000 b260c000 r-xp /usr/lib/libremix.so.0.0.0
b2613000 b2614000 rwxp /usr/lib/libremix.so.0.0.0
b2614000 b261b000 r-xp /usr/lib/libembryo.so.1.7.99
b2623000 b2624000 rwxp /usr/lib/libembryo.so.1.7.99
b2624000 b2648000 r-xp /usr/lib/libjpeg.so.8.0.2
b264f000 b2650000 rwxp /usr/lib/libjpeg.so.8.0.2
b2661000 b2670000 r-xp /usr/lib/libICE.so.6.3.0
b2677000 b2678000 rwxp /usr/lib/libICE.so.6.3.0
b267a000 b267f000 r-xp /usr/lib/libSM.so.6.0.1
b2686000 b2687000 rwxp /usr/lib/libSM.so.6.0.1
b2687000 b2690000 r-xp /usr/lib/libmsg_vobject.so
b2698000 b2699000 rwxp /usr/lib/libmsg_vobject.so
b2699000 b26a3000 r-xp /usr/lib/libdrm-client.so.0.0.1
b26aa000 b26ab000 rwxp /usr/lib/libdrm-client.so.0.0.1
b26ac000 b271e000 r-xp /usr/lib/libcontacts-service2.so.0.9.114.7
b2725000 b273d000 rwxp /usr/lib/libcontacts-service2.so.0.9.114.7
b273d000 b2756000 r-xp /usr/lib/libmsg_plugin_manager.so
b275e000 b275f000 rwxp /usr/lib/libmsg_plugin_manager.so
b275f000 b2798000 r-xp /usr/lib/libmsg_framework_handler.so
b27a0000 b27a1000 rwxp /usr/lib/libmsg_framework_handler.so
b27a1000 b27d5000 r-xp /usr/lib/libmsg_transaction_proxy.so
b27dd000 b27de000 rwxp /usr/lib/libmsg_transaction_proxy.so
b27de000 b281e000 r-xp /usr/lib/libmsg_utils.so
b281e000 b281f000 rwxp /usr/lib/libmsg_utils.so
b2820000 b282f000 r-xp /usr/lib/libemail-common-use.so.1.1.0
b2837000 b2838000 rwxp /usr/lib/libemail-common-use.so.1.1.0
b2838000 b28b3000 r-xp /usr/lib/libemail-core.so.1.1.0
b28ba000 b28c2000 rwxp /usr/lib/libemail-core.so.1.1.0
b28c3000 b290c000 r-xp /usr/lib/libemail-storage.so.1.1.0
b2914000 b2915000 rwxp /usr/lib/libemail-storage.so.1.1.0
b2915000 b2922000 r-xp /usr/lib/libemail-ipc.so.1.1.0
b2929000 b292a000 rwxp /usr/lib/libemail-ipc.so.1.1.0
b292a000 b2930000 r-xp /usr/lib/libshortcut.so.0.0.1
b2938000 b2939000 rwxp /usr/lib/libshortcut.so.0.0.1
b293a000 b2940000 r-xp /usr/lib/libbadge.so.0.0.1
b2947000 b2948000 rwxp /usr/lib/libbadge.so.0.0.1
b2948000 b294e000 r-xp /usr/lib/libcapi-appfw-app-manager.so.0.1.0
b2955000 b2956000 rwxp /usr/lib/libcapi-appfw-app-manager.so.0.1.0
b2956000 b2968000 r-xp /usr/lib/libmmfile_utils.so.0.0.0
b296f000 b2970000 rwxp /usr/lib/libmmfile_utils.so.0.0.0
b2970000 b2975000 r-xp /usr/lib/libmmffile.so.0.0.0
b297c000 b297d000 rwxp /usr/lib/libmmffile.so.0.0.0
b297d000 b297f000 r-xp /usr/lib/libgmodule-2.0.so.0.3200.3
b2986000 b2987000 rwxp /usr/lib/libgmodule-2.0.so.0.3200.3
b2988000 b2a24000 r-xp /usr/lib/libgstreamer-0.10.so.0.30.0
b2a2c000 b2a2f000 rwxp /usr/lib/libgstreamer-0.10.so.0.30.0
b2a30000 b2a71000 r-xp /usr/lib/libgstbase-0.10.so.0.30.0
b2a79000 b2a7a000 rwxp /usr/lib/libgstbase-0.10.so.0.30.0
b2a7a000 b2ade000 r-xp /usr/lib/libmmfcamcorder.so.0.0.0
b2ae6000 b2aeb000 rwxp /usr/lib/libmmfcamcorder.so.0.0.0
b2aeb000 b2aee000 r-xp /usr/lib/libmm_ta.so.0.0.0
b2af5000 b2af6000 rwxp /usr/lib/libmm_ta.so.0.0.0
b2af7000 b2b28000 r-xp /usr/lib/libpulse.so.0.12.4
b2b2f000 b2b30000 rwxp /usr/lib/libpulse.so.0.12.4
b2b30000 b2b93000 r-xp /usr/lib/libasound.so.2.0.0
b2b9a000 b2b9d000 rwxp /usr/lib/libasound.so.2.0.0
b2b9d000 b2ba0000 r-xp /usr/lib/libpulse-simple.so.0.0.3
b2ba7000 b2ba8000 rwxp /usr/lib/libpulse-simple.so.0.0.3
b2ba8000 b2bac000 r-xp /usr/lib/libascenario-0.2.so.0.0.0
b2bb4000 b2bb5000 rwxp /usr/lib/libascenario-0.2.so.0.0.0
b2bb5000 b2bd2000 r-xp /usr/lib/libavsysaudio.so.0.0.1
b2bd9000 b2bda000 rwxp /usr/lib/libavsysaudio.so.0.0.1
b2bda000 b2be8000 r-xp /usr/lib/libmmfsound.so.0.1.0
b2bef000 b2bf0000 rwxp /usr/lib/libmmfsound.so.0.1.0
b2bf1000 b2c1d000 r-xp /usr/lib/libidn.so.11.5.44
b2c25000 b2c26000 rwxp /usr/lib/libidn.so.11.5.44
b2c26000 b2c30000 r-xp /usr/lib/libcares.so.2.0.0
b2c37000 b2c38000 rwxp /usr/lib/libcares.so.2.0.0
b2c38000 b2c4c000 r-xp /usr/lib/libnetwork.so.0.0.0
b2c53000 b2c54000 rwxp /usr/lib/libnetwork.so.0.0.0
b2c55000 b2c5d000 r-xp /lib/libcrypt-2.13.so
b2c64000 b2c65000 r-xp /lib/libcrypt-2.13.so
b2c65000 b2c66000 rwxp /lib/libcrypt-2.13.so
b2c8d000 b2c90000 r-xp /lib/libcap.so.2.21
b2c97000 b2c98000 rwxp /lib/libcap.so.2.21
b2c99000 b2c9b000 r-xp /usr/lib/libiri.so
b2ca2000 b2ca3000 rwxp /usr/lib/libiri.so
b2ca3000 b2cb4000 r-xp /usr/lib/libsecurity-server-commons.so.1.0.0
b2cbc000 b2cbd000 rwxp /usr/lib/libsecurity-server-commons.so.1.0.0
b2cbd000 b2cbf000 r-xp /usr/lib/libsystemd-daemon.so.0.0.1
b2cc6000 b2cc7000 rwxp /usr/lib/libsystemd-daemon.so.0.0.1
b2cc7000 b2cc8000 r-xp /usr/lib/libgthread-2.0.so.0.3200.3
b2ccf000 b2cd0000 rwxp /usr/lib/libgthread-2.0.so.0.3200.3
b2cd1000 b2cd3000 r-xp /usr/lib/libdeviced.so.0.1.0
b2cda000 b2cdb000 rwxp /usr/lib/libdeviced.so.0.1.0
b2cdb000 b2cf1000 r-xp /usr/lib/libpkgmgr_parser.so.0.1.0
b2cf8000 b2cf9000 rwxp /usr/lib/libpkgmgr_parser.so.0.1.0
b2cf9000 b2cfb000 r-xp /usr/lib/libpkgmgr_installer_status_broadcast_server.so.0.1.0
b2d02000 b2d03000 rwxp /usr/lib/libpkgmgr_installer_status_broadcast_server.so.0.1.0
b2d03000 b2d06000 r-xp /usr/lib/libpkgmgr_installer_client.so.0.1.0
b2d0d000 b2d0e000 rwxp /usr/lib/libpkgmgr_installer_client.so.0.1.0
b2d0f000 b2d20000 r-xp /usr/lib/libcom-core.so.0.0.1
b2d27000 b2d28000 rwxp /usr/lib/libcom-core.so.0.0.1
b2d28000 b2d2b000 r-xp /usr/lib/libdevice-node.so.0.1
b2d32000 b2d33000 rwxp /usr/lib/libdevice-node.so.0.1
b2d33000 b2d37000 r-xp /usr/lib/libheynoti.so.0.0.2
b2d3e000 b2d3f000 rwxp /usr/lib/libheynoti.so.0.0.2
b2d3f000 b2d41000 r-xp /usr/lib/libapp-checker.so.0.1.0
b2d48000 b2d49000 rwxp /usr/lib/libapp-checker.so.0.1.0
b2d4a000 b2d4d000 r-xp /usr/lib/libsmack.so.1.0.0
b2d54000 b2d55000 rwxp /usr/lib/libsmack.so.1.0.0
b2d55000 b2d56000 r-xp /usr/lib/libmmfkeysound.so.0.0.0
b2d5d000 b2d5e000 rwxp /usr/lib/libmmfkeysound.so.0.0.0
b2d5e000 b2d66000 r-xp /usr/lib/libmmfcommon.so.0.0.0
b2d6d000 b2d6e000 rwxp /usr/lib/libmmfcommon.so.0.0.0
b2d6e000 b2d72000 r-xp /usr/lib/libsysman.so.0.2.0
b2d79000 b2d7a000 rwxp /usr/lib/libsysman.so.0.2.0
b2d7b000 b2d83000 r-xp /usr/lib/libaudio-session-mgr.so.0.0.0
b2d8a000 b2d8b000 rwxp /usr/lib/libaudio-session-mgr.so.0.0.0
b2d8e000 b2d91000 r-xp /usr/lib/libmmfsession.so.0.0.0
b2d98000 b2d99000 rwxp /usr/lib/libmmfsession.so.0.0.0
b2d99000 b2ddd000 r-xp /usr/lib/libmmfplayer.so.0.0.0
b2de4000 b2de5000 rwxp /usr/lib/libmmfplayer.so.0.0.0
b2de6000 b2df9000 r-xp /usr/lib/libEGL_platform.so
b2e01000 b2e02000 rwxp /usr/lib/libEGL_platform.so
b2e02000 b2ed9000 r-xp /usr/lib/libMali.so
b2ee1000 b2ee4000 rwxp /usr/lib/libMali.so
b2ee5000 b2f09000 r-xp /usr/lib/libicule.so.48.1
b2f11000 b2f12000 rwxp /usr/lib/libicule.so.48.1
b2f12000 b2f18000 r-xp /usr/lib/libxcb-render.so.0.0.0
b2f1f000 b2f20000 rwxp /usr/lib/libxcb-render.so.0.0.0
b2f20000 b2f21000 r-xp /usr/lib/libxcb-shm.so.0.0.0
b2f29000 b2f2a000 rwxp /usr/lib/libxcb-shm.so.0.0.0
b2f2a000 b2f68000 r-xp /usr/lib/libGLESv2.so.2.0
b2f6f000 b2f70000 rwxp /usr/lib/libGLESv2.so.2.0
b2f70000 b2f87000 r-xp /lib/libexpat.so.1.5.2
b2f8f000 b2f91000 rwxp /lib/libexpat.so.1.5.2
b2f92000 b2f95000 r-xp /usr/lib/libecore_input_evas.so.1.7.99
b2f9c000 b2f9d000 rwxp /usr/lib/libecore_input_evas.so.1.7.99
b2f9d000 b2fa1000 r-xp /usr/lib/libecore_ipc.so.1.7.99
b2fa9000 b2faa000 rwxp /usr/lib/libecore_ipc.so.1.7.99
b2faa000 b2fb0000 r-xp /usr/lib/libXrender.so.1.3.0
b2fb7000 b2fb8000 rwxp /usr/lib/libXrender.so.1.3.0
b2fb8000 b2fbe000 r-xp /usr/lib/libXrandr.so.2.2.0
b2fc5000 b2fc6000 rwxp /usr/lib/libXrandr.so.2.2.0
b2fc7000 b2fc8000 r-xp /usr/lib/libXinerama.so.1.0.0
b2fd0000 b2fd1000 rwxp /usr/lib/libXinerama.so.1.0.0
b2fd1000 b2fda000 r-xp /usr/lib/libXi.so.6.1.0
b2fe1000 b2fe2000 rwxp /usr/lib/libXi.so.6.1.0
b2fe2000 b2fe4000 r-xp /usr/lib/libXgesture.so.7.0.0
b2feb000 b2fec000 rwxp /usr/lib/libXgesture.so.7.0.0
b2fec000 b2fee000 r-xp /usr/lib/libXcomposite.so.1.0.0
b2ff5000 b2ff6000 rwxp /usr/lib/libXcomposite.so.1.0.0
b2ff6000 b2ffd000 r-xp /usr/lib/libXcursor.so.1.0.2
b3004000 b3005000 rwxp /usr/lib/libXcursor.so.1.0.2
b3006000 b3009000 r-xp /usr/lib/libXfixes.so.3.1.0
b3010000 b3011000 rwxp /usr/lib/libXfixes.so.3.1.0
b3011000 b3026000 r-xp /usr/lib/libxcb.so.1.1.0
b302d000 b302e000 rwxp /usr/lib/libxcb.so.1.1.0
b302e000 b3036000 r-xp /usr/lib/libemotion.so.1.7.99
b303d000 b303e000 rwxp /usr/lib/libemotion.so.1.7.99
b303e000 b3043000 r-xp /usr/lib/libecore_fb.so.1.7.99
b304a000 b304c000 rwxp /usr/lib/libecore_fb.so.1.7.99
b304c000 b3054000 r-xp /usr/lib/libsf_common.so
b305b000 b305c000 rwxp /usr/lib/libsf_common.so
b305d000 b313a000 r-xp /usr/lib/libgio-2.0.so.0.3200.3
b3141000 b3144000 rwxp /usr/lib/libgio-2.0.so.0.3200.3
b3145000 b318a000 r-xp /usr/lib/libsoup-2.4.so.1.5.0
b3191000 b3193000 rwxp /usr/lib/libsoup-2.4.so.1.5.0
b3193000 b31c7000 r-xp /usr/lib/libgobject-2.0.so.0.3200.3
b31ce000 b31d0000 rwxp /usr/lib/libgobject-2.0.so.0.3200.3
b31d0000 b31eb000 r-xp /usr/lib/libecore_con.so.1.7.99
b31f2000 b31f3000 rwxp /usr/lib/libecore_con.so.1.7.99
b31f4000 b31fc000 r-xp /usr/lib/libethumb_client.so.1.7.99
b3203000 b3204000 rwxp /usr/lib/libethumb_client.so.1.7.99
b3205000 b320e000 r-xp /usr/lib/libedbus.so.1.7.99
b3215000 b3216000 rwxp /usr/lib/libedbus.so.1.7.99
b3216000 b3218000 r-xp /usr/lib/libefreet_trash.so.1.7.99
b321f000 b3220000 rwxp /usr/lib/libefreet_trash.so.1.7.99
b3220000 b3224000 r-xp /usr/lib/libefreet_mime.so.1.7.99
b322c000 b322d000 rwxp /usr/lib/libefreet_mime.so.1.7.99
b322d000 b3243000 r-xp /usr/lib/libefreet.so.1.7.99
b324b000 b324c000 rwxp /usr/lib/libefreet.so.1.7.99
b324d000 b32a9000 r-xp /usr/lib/libedje.so.1.7.99
b32b1000 b32b3000 rwxp /usr/lib/libedje.so.1.7.99
b32b3000 b32b8000 r-xp /usr/lib/libecore_file.so.1.7.99
b32bf000 b32c0000 rwxp /usr/lib/libecore_file.so.1.7.99
b32c1000 b32d4000 r-xp /usr/lib/libeet.so.1.7.99
b32dc000 b32dd000 rwxp /usr/lib/libeet.so.1.7.99
b32dd000 b43e4000 r-xp /usr/lib/libicudata.so.48.1
b43eb000 b43ec000 rwxp /usr/lib/libicudata.so.48.1
b43ec000 b43ef000 r-xp /usr/lib/libSLP-db-util.so.0.1.0
b43f6000 b43f7000 rwxp /usr/lib/libSLP-db-util.so.0.1.0
b43f7000 b43fd000 r-xp /usr/lib/libxdgmime.so.1.1.0
b4404000 b4405000 rwxp /usr/lib/libxdgmime.so.1.1.0
b4405000 b4413000 r-xp /usr/lib/libail.so.0.1.0
b441a000 b441b000 rwxp /usr/lib/libail.so.0.1.0
b441c000 b4441000 r-xp /usr/lib/libexif.so.12.3.3
b4448000 b4455000 rwxp /usr/lib/libexif.so.12.3.3
b4455000 b44a0000 r-xp /usr/lib/libtiff.so.5.1.0
b44a8000 b44ab000 rwxp /usr/lib/libtiff.so.5.1.0
b44ab000 b44d4000 r-xp /usr/lib/libturbojpeg.so
b44dc000 b44dd000 rwxp /usr/lib/libturbojpeg.so
b44ed000 b44f3000 r-xp /usr/lib/libmmutil_imgp.so.0.0.0
b44fa000 b44fb000 rwxp /usr/lib/libmmutil_imgp.so.0.0.0
b44fb000 b4501000 r-xp /usr/lib/libgif.so.4.1.6
b4508000 b4509000 rwxp /usr/lib/libgif.so.4.1.6
b4509000 b4522000 r-xp /usr/lib/libpng12.so.0.50.0
b452a000 b452b000 rwxp /usr/lib/libpng12.so.0.50.0
b452c000 b4534000 r-xp /usr/lib/libpush.so.0.2.12
b453b000 b453c000 rwxp /usr/lib/libpush.so.0.2.12
b453c000 b4557000 r-xp /usr/lib/libmsg_mapi.so.0.1.0
b455f000 b4560000 rwxp /usr/lib/libmsg_mapi.so.0.1.0
b4560000 b4578000 r-xp /usr/lib/libemail-api.so.1.1.0
b457f000 b4580000 rwxp /usr/lib/libemail-api.so.1.1.0
b4580000 b459e000 r-xp /usr/lib/osp/libosp-shell-core.so.1.2.2.1
b45a5000 b45a7000 rwxp /usr/lib/osp/libosp-shell-core.so.1.2.2.1
b45a7000 b45c1000 r-xp /usr/lib/osp/libosp-json.so.1.2.2.0
b45c9000 b45cb000 rwxp /usr/lib/osp/libosp-json.so.1.2.2.0
b45cc000 b45d1000 r-xp /usr/lib/libcapi-media-metadata-extractor.so
b45d8000 b45d9000 rwxp /usr/lib/libcapi-media-metadata-extractor.so
b45d9000 b45de000 r-xp /usr/lib/libcapi-media-recorder.so.0.1.3
b45e5000 b45e6000 rwxp /usr/lib/libcapi-media-recorder.so.0.1.3
b45e6000 b45f1000 r-xp /usr/lib/libcapi-media-camera.so.0.1.4
b45f8000 b45f9000 rwxp /usr/lib/libcapi-media-camera.so.0.1.4
b45f9000 b45fc000 r-xp /usr/lib/libcapi-media-sound-manager.so.0.1.1
b4603000 b4604000 rwxp /usr/lib/libcapi-media-sound-manager.so.0.1.1
b4604000 b4612000 r-xp /usr/lib/libcapi-media-player.so.0.1.1
b4619000 b461a000 rwxp /usr/lib/libcapi-media-player.so.0.1.1
b461b000 b463c000 r-xp /usr/lib/libopencore-amrnb.so.0.0.2
b4644000 b4645000 rwxp /usr/lib/libopencore-amrnb.so.0.0.2
b4645000 b4649000 r-xp /usr/lib/libogg.so.0.7.1
b4650000 b4651000 rwxp /usr/lib/libogg.so.0.7.1
b4651000 b4673000 r-xp /usr/lib/libvorbis.so.0.4.3
b467a000 b467b000 rwxp /usr/lib/libvorbis.so.0.4.3
b467b000 b469d000 r-xp /usr/lib/libavutil.so.51.73.101
b46a5000 b46a8000 rwxp /usr/lib/libavutil.so.51.73.101
b46ac000 b49a3000 r-xp /usr/lib/libavcodec.so.54.59.100
b49ab000 b49bb000 rwxp /usr/lib/libavcodec.so.54.59.100
b4cca000 b4cf8000 r-xp /usr/lib/libswscale.so.2.1.101
b4d00000 b4d01000 rwxp /usr/lib/libswscale.so.2.1.101
b4d02000 b4d06000 r-xp /usr/lib/libcapi-media-audio-io.so.0.2.0
b4d0d000 b4d0e000 rwxp /usr/lib/libcapi-media-audio-io.so.0.2.0
b4d0e000 b4d22000 r-xp /usr/lib/libwifi-direct.so.0.0
b4d29000 b4d2a000 rwxp /usr/lib/libwifi-direct.so.0.0
b4d2a000 b4d67000 r-xp /usr/lib/libcurl.so.4.3.0
b4d6f000 b4d71000 rwxp /usr/lib/libcurl.so.4.3.0
b4d71000 b4dbd000 r-xp /usr/lib/libssl.so.1.0.0
b4dc4000 b4dc9000 rwxp /usr/lib/libssl.so.1.0.0
b4dc9000 b4dd1000 r-xp /usr/lib/libcapi-network-tethering.so.0.1.0
b4dd1000 b4dd2000 rwxp /usr/lib/libcapi-network-tethering.so.0.1.0
b4dd3000 b4ddc000 r-xp /usr/lib/libcapi-network-connection.so.0.1.3_18
b4de3000 b4de4000 rwxp /usr/lib/libcapi-network-connection.so.0.1.3_18
b4de4000 b4df1000 r-xp /usr/lib/libprivilege-control.so.0.0.2
b4df9000 b4dfa000 rwxp /usr/lib/libprivilege-control.so.0.0.2
b4dfa000 b4f4d000 r-xp /usr/lib/libcrypto.so.1.0.0
b4f55000 b4f68000 rwxp /usr/lib/libcrypto.so.1.0.0
b4f6b000 b4f80000 r-xp /usr/lib/libsecurity-server-client.so.1.0.1
b4f88000 b4f89000 rwxp /usr/lib/libsecurity-server-client.so.1.0.1
b4f89000 b4f8d000 r-xp /usr/lib/libcapi-system-info.so.0.2.0
b4f94000 b4f95000 rwxp /usr/lib/libcapi-system-info.so.0.2.0
b4f96000 b4f9b000 r-xp /usr/lib/libcapi-system-system-settings.so.0.0.2
b4fa2000 b4fa3000 rwxp /usr/lib/libcapi-system-system-settings.so.0.0.2
b4fa3000 b4fa4000 r-xp /usr/lib/libcapi-system-power.so.0.1.1
b4fac000 b4fad000 rwxp /usr/lib/libcapi-system-power.so.0.1.1
b4fad000 b4fb0000 r-xp /usr/lib/libcapi-system-device.so.0.1.0
b4fb7000 b4fb8000 rwxp /usr/lib/libcapi-system-device.so.0.1.0
b4fb8000 b4fbb000 r-xp /usr/lib/libcapi-network-serial.so.0.0.8
b4fc2000 b4fc3000 rwxp /usr/lib/libcapi-network-serial.so.0.0.8
b4fc3000 b4fc4000 r-xp /usr/lib/libcapi-content-mime-type.so.0.0.2
b4fcb000 b4fcc000 rwxp /usr/lib/libcapi-content-mime-type.so.0.0.2
b4fcd000 b4fef000 r-xp /usr/lib/libSLP-tapi.so.0.0.0
b4ff6000 b4ff7000 rwxp /usr/lib/libSLP-tapi.so.0.0.0
b4ff7000 b500e000 r-xp /lib/libz.so.1.2.5
b5015000 b5016000 rwxp /lib/libz.so.1.2.5
b5016000 b5019000 r-xp /usr/lib/libuuid.so.1.3.0
b5021000 b5022000 rwxp /usr/lib/libuuid.so.1.3.0
b5022000 b508c000 r-xp /usr/lib/libsqlite3.so.0.8.6
b5093000 b5095000 rwxp /usr/lib/libsqlite3.so.0.8.6
b5096000 b50b4000 r-xp /usr/lib/libpkgmgr-info.so.0.0.17
b50bb000 b50bc000 rwxp /usr/lib/libpkgmgr-info.so.0.0.17
b50bc000 b50e8000 r-xp /usr/lib/libdbus-1.so.3.7.2
b50f0000 b50f1000 rwxp /usr/lib/libdbus-1.so.3.7.2
b50f2000 b510a000 r-xp /usr/lib/libdbus-glib-1.so.2.2.2
b510a000 b510b000 rwxp /usr/lib/libdbus-glib-1.so.2.2.2
b510b000 b510c000 r-xp /usr/lib/libdlog.so.0.0.0
b5113000 b5114000 rwxp /usr/lib/libdlog.so.0.0.0
b5114000 b512b000 r-xp /usr/lib/libpkgmgr-client.so.0.1.68
b5133000 b5134000 rwxp /usr/lib/libpkgmgr-client.so.0.1.68
b5134000 b5135000 r-xp /usr/lib/libpmapi.so.1.2
b513c000 b513d000 rwxp /usr/lib/libpmapi.so.1.2
b513d000 b5141000 r-xp /usr/lib/libbundle.so.0.1.22
b5148000 b5149000 rwxp /usr/lib/libbundle.so.0.1.22
b5149000 b5159000 r-xp /usr/lib/libnotification.so.0.1.0
b5160000 b5161000 rwxp /usr/lib/libnotification.so.0.1.0
b5162000 b516a000 r-xp /usr/lib/libminizip.so.1.0.0
b5171000 b5172000 rwxp /usr/lib/libminizip.so.1.0.0
b5172000 b517d000 r-xp /usr/lib/libmessage-port.so.1.2.2.1
b5184000 b5185000 rwxp /usr/lib/libmessage-port.so.1.2.2.1
b5185000 b51a3000 r-xp /usr/lib/libpcre.so.0.0.1
b51aa000 b51ab000 rwxp /usr/lib/libpcre.so.0.0.1
b51ab000 b51ae000 r-xp /usr/lib/libiniparser.so.0
b51b5000 b51b6000 rwxp /usr/lib/libiniparser.so.0
b51b7000 b529f000 r-xp /usr/lib/libicuuc.so.48.1
b529f000 b52aa000 rwxp /usr/lib/libicuuc.so.48.1
b52ac000 b53cc000 r-xp /usr/lib/libicui18n.so.48.1
b53d3000 b53d9000 rwxp /usr/lib/libicui18n.so.48.1
b53db000 b53df000 r-xp /usr/lib/libhaptic.so.0.1
b53e6000 b53e7000 rwxp /usr/lib/libhaptic.so.0.1
b53e7000 b53f2000 r-xp /usr/lib/libcryptsvc.so.0.0.1
b53fa000 b53fb000 rwxp /usr/lib/libcryptsvc.so.0.0.1
b53ff000 b5404000 r-xp /usr/lib/libdevman.so.0.1
b540c000 b540d000 rwxp /usr/lib/libdevman.so.0.1
b540d000 b5418000 r-xp /usr/lib/libaul.so.0.1.0
b5420000 b5421000 rwxp /usr/lib/libaul.so.0.1.0
b5421000 b5422000 r-xp /usr/lib/osp/libappinfo.so.1.2.2.1
b5429000 b542a000 rwxp /usr/lib/osp/libappinfo.so.1.2.2.1
b542b000 b5431000 r-xp /usr/lib/libalarm.so.0.0.0
b5439000 b543a000 rwxp /usr/lib/libalarm.so.0.0.0
b543a000 b5443000 r-xp /usr/lib/libcapi-security-privilege-manager.so.0.0.3
b544b000 b544c000 rwxp /usr/lib/libcapi-security-privilege-manager.so.0.0.3
b544c000 b545e000 r-xp /usr/lib/libprivacy-manager-client.so.0.0.5
b5465000 b5466000 rwxp /usr/lib/libprivacy-manager-client.so.0.0.5
b5466000 b546c000 r-xp /lib/librt-2.13.so
b5473000 b5474000 r-xp /lib/librt-2.13.so
b5474000 b5475000 rwxp /lib/librt-2.13.so
b5475000 b54df000 r-xp /lib/libm-2.13.so
b54e6000 b54e7000 r-xp /lib/libm-2.13.so
b54e7000 b54e8000 rwxp /lib/libm-2.13.so
b54e8000 b54ec000 r-xp /usr/lib/libchromium.so.1.0
b54f3000 b54f4000 rwxp /usr/lib/libchromium.so.1.0
b54f5000 b54f8000 r-xp /usr/lib/libXtst.so.6.1.0
b54ff000 b5500000 rwxp /usr/lib/libXtst.so.6.1.0
b5500000 b5507000 r-xp /usr/lib/libutilX.so.1.1.0
b550e000 b550f000 rwxp /usr/lib/libutilX.so.1.1.0
b550f000 b5512000 r-xp /usr/lib/libcapi-system-runtime-info.so.0.0.3
b551a000 b551b000 rwxp /usr/lib/libcapi-system-runtime-info.so.0.0.3
b551b000 b5534000 r-xp /usr/lib/liblua-5.1.so
b553c000 b553d000 rwxp /usr/lib/liblua-5.1.so
b553d000 b5541000 r-xp /usr/lib/libtbm.so.1.0.0
b5548000 b5549000 rwxp /usr/lib/libtbm.so.1.0.0
b554a000 b5552000 r-xp /usr/lib/libdrm.so.2.4.0
b5559000 b555a000 rwxp /usr/lib/libdrm.so.2.4.0
b555a000 b555c000 r-xp /usr/lib/libdri2.so.0.0.0
b5563000 b5564000 rwxp /usr/lib/libdri2.so.0.0.0
b5564000 b556a000 r-xp /usr/lib/libfeedback.so.0.1.4
b5571000 b5572000 rwxp /usr/lib/libfeedback.so.0.1.4
b5572000 b557e000 r-xp /usr/lib/libtts.so
b5585000 b5586000 rwxp /usr/lib/libtts.so
b5586000 b5589000 r-xp /usr/lib/libXv.so.1.0.0
b5590000 b5591000 rwxp /usr/lib/libXv.so.1.0.0
b5591000 b55a8000 r-xp /usr/lib/libEGL.so.1.4
b55b0000 b55b1000 rwxp /usr/lib/libEGL.so.1.4
b55b2000 b55bc000 r-xp /usr/lib/libXext.so.6.4.0
b55c4000 b55c5000 rwxp /usr/lib/libXext.so.6.4.0
b55c5000 b5621000 r-xp /usr/lib/libharfbuzz.so.0.907.0
b5629000 b5633000 rwxp /usr/lib/libharfbuzz.so.0.907.0
b5633000 b5647000 r-xp /usr/lib/libfribidi.so.0.3.1
b564e000 b564f000 rwxp /usr/lib/libfribidi.so.0.3.1
b564f000 b56a4000 r-xp /usr/lib/libfreetype.so.6.8.1
b56ab000 b56af000 rwxp /usr/lib/libfreetype.so.6.8.1
b56af000 b5789000 r-xp /usr/lib/libglib-2.0.so.0.3200.3
b5791000 b5792000 rwxp /usr/lib/libglib-2.0.so.0.3200.3
b5792000 b57fc000 r-xp /usr/lib/libpixman-1.so.0.28.2
b5804000 b5809000 rwxp /usr/lib/libpixman-1.so.0.28.2
b580a000 b58c1000 r-xp /usr/lib/libcairo.so.2.11200.12
b58c8000 b58cb000 rwxp /usr/lib/libcairo.so.2.11200.12
b58cb000 b58ef000 r-xp /usr/lib/libfontconfig.so.1.5.0
b58f6000 b58f8000 rwxp /usr/lib/libfontconfig.so.1.5.0
b58f8000 b59d0000 r-xp /usr/lib/libxml2.so.2.7.8
b59d7000 b59dd000 rwxp /usr/lib/libxml2.so.2.7.8
b59dd000 b59f4000 r-xp /usr/lib/libecore_input.so.1.7.99
b59fb000 b5a0f000 rwxp /usr/lib/libecore_input.so.1.7.99
b5a0f000 b5a10000 r-xp /usr/lib/libecore_imf_evas.so.1.7.99
b5a17000 b5a18000 rwxp /usr/lib/libecore_imf_evas.so.1.7.99
b5a19000 b5a1e000 r-xp /usr/lib/libecore_imf.so.1.7.99
b5a26000 b5a27000 rwxp /usr/lib/libecore_imf.so.1.7.99
b5a27000 b5a57000 r-xp /usr/lib/libecore_x.so.1.7.99
b5a5e000 b5a60000 rwxp /usr/lib/libecore_x.so.1.7.99
b5a60000 b5a7d000 r-xp /usr/lib/libecore_evas.so.1.7.99
b5a84000 b5a86000 rwxp /usr/lib/libecore_evas.so.1.7.99
b5a86000 b5ac5000 r-xp /usr/lib/libeina.so.1.7.99
b5acc000 b5ace000 rwxp /usr/lib/libeina.so.1.7.99
b5ace000 b5b7d000 r-xp /usr/lib/libevas.so.1.7.99
b5b85000 b5b8d000 rwxp /usr/lib/libevas.so.1.7.99
b5b9f000 b5bb4000 r-xp /usr/lib/libecore.so.1.7.99
b5bbc000 b5bbd000 rwxp /usr/lib/libecore.so.1.7.99
b5bcb000 b5bdf000 r-xp /lib/libpthread-2.13.so
b5be6000 b5be7000 r-xp /lib/libpthread-2.13.so
b5be7000 b5be8000 rwxp /lib/libpthread-2.13.so
b5bea000 b5bf3000 r-xp /usr/lib/libvconf.so.0.2.45
b5bfa000 b5bfb000 rwxp /usr/lib/libvconf.so.0.2.45
b5bfb000 b5bfc000 r-xp /usr/lib/libXdamage.so.1.1.0
b5c04000 b5c05000 rwxp /usr/lib/libXdamage.so.1.1.0
b5c05000 b5ceb000 r-xp /usr/lib/libX11.so.6.3.0
b5cf2000 b5cf6000 rwxp /usr/lib/libX11.so.6.3.0
b5cf6000 b5e16000 r-xp /usr/lib/libelementary.so.1.7.99
b5e1d000 b5e24000 rwxp /usr/lib/libelementary.so.1.7.99
b5e28000 b5e35000 r-xp /usr/lib/libsensor.so.1.1.0
b5e3d000 b5e3e000 rwxp /usr/lib/libsensor.so.1.1.0
b5e40000 b5e46000 r-xp /usr/lib/libappsvc.so.0.1.0
b5e4d000 b5e4e000 rwxp /usr/lib/libappsvc.so.0.1.0
b5e4e000 b5e52000 r-xp /usr/lib/libappcore-efl.so.1.1
b5e59000 b5e5a000 rwxp /usr/lib/libappcore-efl.so.1.1
b5e5a000 b5e5f000 r-xp /usr/lib/libappcore-common.so.1.1
b5e66000 b5e67000 rwxp /usr/lib/libappcore-common.so.1.1
b5e67000 b5e75000 r-xp /usr/lib/libcapi-appfw-application.so.0.1.0
b5e7c000 b5e7d000 rwxp /usr/lib/libcapi-appfw-application.so.0.1.0
b5e7e000 b5e98000 r-xp /usr/lib/osp/libosp-image-core.so.1.2.2.0
b5ea0000 b5ea1000 rwxp /usr/lib/osp/libosp-image-core.so.1.2.2.0
b5ea1000 b5ea3000 r-xp /lib/libdl-2.13.so
b5eaa000 b5eab000 r-xp /lib/libdl-2.13.so
b5eab000 b5eac000 rwxp /lib/libdl-2.13.so
b5eac000 b5eb7000 r-xp /lib/libunwind.so.8.0.1
b5ebf000 b5ec0000 rwxp /lib/libunwind.so.8.0.1
b5ee5000 b6002000 r-xp /lib/libc-2.13.so
b600a000 b600c000 r-xp /lib/libc-2.13.so
b600c000 b600d000 rwxp /lib/libc-2.13.so
b6010000 b6019000 r-xp /lib/libgcc_s-4.5.3.so.1
b6020000 b6021000 rwxp /lib/libgcc_s-4.5.3.so.1
b6021000 b60bc000 r-xp /usr/lib/libstdc++.so.6.0.14
b60c4000 b60c7000 r-xp /usr/lib/libstdc++.so.6.0.14
b60c7000 b60c9000 rwxp /usr/lib/libstdc++.so.6.0.14
b60cf000 b611c000 r-xp /usr/lib/osp/libosp-messaging.so.1.2.2.0
b6124000 b6126000 rwxp /usr/lib/osp/libosp-messaging.so.1.2.2.0
b6126000 b621c000 r-xp /usr/lib/osp/libosp-media.so.1.2.2.0
b6224000 b622f000 rwxp /usr/lib/osp/libosp-media.so.1.2.2.0
b622f000 b62f4000 r-xp /usr/lib/osp/libosp-net.so.1.2.2.0
b62fc000 b6302000 rwxp /usr/lib/osp/libosp-net.so.1.2.2.0
b6302000 b631f000 r-xp /usr/lib/osp/libosp-image.so.1.2.2.0
b6327000 b6328000 rwxp /usr/lib/osp/libosp-image.so.1.2.2.0
b6328000 b6627000 r-xp /usr/lib/osp/libosp-appfw.so.1.2.2.1
b662f000 b664d000 rwxp /usr/lib/osp/libosp-appfw.so.1.2.2.1
b664e000 b6f49000 r-xp /usr/lib/osp/libosp-uifw.so.1.2.2.1
b6f50000 b6fb9000 rwxp /usr/lib/osp/libosp-uifw.so.1.2.2.1
b6fbd000 b6fbe000 r-xp /usr/lib/locale/locale-archive
b6fbe000 b6fbf000 r-xs /var/cache/fontconfig/3830d5c3ddfd5cd38a049b759396e72e-le32d8.cache-3
b6fc0000 b6fc5000 r-xp /usr/lib/libslp_devman_plugin.so
b6fcd000 b6fce000 rwxp /usr/lib/libslp_devman_plugin.so
b6fce000 b6fd2000 r-xp /usr/lib/libsys-assert.so
b6fd9000 b6fda000 rwxp /usr/lib/libsys-assert.so
b6fda000 b6ff7000 r-xp /lib/ld-2.13.so
b6ffe000 b6fff000 r-xp /lib/ld-2.13.so
b6fff000 b7000000 rwxp /lib/ld-2.13.so
befdf000 bf000000 rwxp [stack]
End of Maps Information

Callstack Information (PID:20447)
Call Stack Count: 30
 0: Tizen::Graphics::Rectangle::Rectangle(Tizen::Graphics::Rectangle const&) + 0xf (0xb6c7a49c) [/usr/lib/osp/libosp-uifw.so.1] + 0x62c49c
 1: (0x2a039ca4) [/opt/apps/X4TuAhqX38/bin/TizenProject] + 0x39ca4
 2: (0x2a039b8c) [/opt/apps/X4TuAhqX38/bin/TizenProject] + 0x39b8c
 3: (0x2a039e20) [/opt/apps/X4TuAhqX38/bin/TizenProject] + 0x39e20
 4: Tizen::Ui::_ControlImpl::CoreTouchEvent::ProcessListener(Tizen::Ui::_TouchInfo const&) + 0x224 (0xb691b7fd) [/usr/lib/osp/libosp-uifw.so.1] + 0x2cd7fd
 5: Tizen::Ui::_ControlImpl::CallOnTouchPressed(Tizen::Ui::_Control const&, Tizen::Ui::_TouchInfo const&) + 0xac (0xb69148dd) [/usr/lib/osp/libosp-uifw.so.1] + 0x2c68dd
 6: Tizen::Ui::_ControlImpl::_PropagatedTouchEventListener::OnTouchPressed(Tizen::Ui::_Control const&, Tizen::Ui::_TouchInfo const&) + 0x200 (0xb691c279) [/usr/lib/osp/libosp-uifw.so.1] + 0x2ce279
 7: Tizen::Ui::_UiTouchEvent::FireListener(Tizen::Ui::_ITouchEventListener const*, Tizen::Ui::_Control const*, bool, bool&) + 0x2de (0xb698296b) [/usr/lib/osp/libosp-uifw.so.1] + 0x33496b
 8: Tizen::Ui::_UiTouchEvent::OnEventProcessing(Tizen::Ui::_Control const&, bool&) + 0x62 (0xb6982e43) [/usr/lib/osp/libosp-uifw.so.1] + 0x334e43
 9: Tizen::Ui::_UiEvent::ProcessEvent(Tizen::Ui::_Control const&, bool&) + 0x32 (0xb6976f53) [/usr/lib/osp/libosp-uifw.so.1] + 0x328f53
10: Tizen::Ui::_UiEventManager::ProcessBubblingEvent(Tizen::Base::Collection::LinkedListT<Tizen::Base::_HandleT<Tizen::Ui::_Control> > const&, Tizen::Ui::_UiEvent const&, bool&) + 0x78 (0xb6977901) [/usr/lib/osp/libosp-uifw.so.1] + 0x329901
11: Tizen::Ui::_UiEventManager::ProcessEvent(Tizen::Ui::_UiEvent const&, bool&) + 0x234 (0xb6977bd5) [/usr/lib/osp/libosp-uifw.so.1] + 0x329bd5
12: Tizen::Ui::_UiEventManager::Fire(Tizen::Ui::_UiEvent const&) + 0x8c (0xb6977cb9) [/usr/lib/osp/libosp-uifw.so.1] + 0x329cb9
13: Tizen::Ui::_UiEventManager::SendEvent(Tizen::Ui::_UiEvent const&) + 0x6 (0xb6977d4b) [/usr/lib/osp/libosp-uifw.so.1] + 0x329d4b
End of Call Stack

Package Information
Package Name: X4TuAhqX38.TizenProject
Package ID : X4TuAhqX38
Version: 1.0.0
Package Type: tpk
App Name: TizenProject
App ID: X4TuAhqX38.TizenProject
Type: Application
Categories: (NULL)
