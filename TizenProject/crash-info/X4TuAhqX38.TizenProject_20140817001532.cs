S/W Version Information
Model: Ref.Device-PQ
Tizen-Version: 2.2.1
Build-Number: Tizen_Ref.Device-PQ_20131118.1124
Build-Date: 2013.11.18 11:24:59

Crash Information
Process Name: TizenProject
PID: 25797
Date: 2014-08-17 00:15:32(GMT+0900)
Executable File Path: /opt/apps/X4TuAhqX38/bin/TizenProject
This process is multi-thread process
pid=25797 tid=25797
Signal: 11
      (SIGSEGV)
      si_code: -6
      signal sent by tkill (sent by pid 25797, uid 5000)

Register Information
r0   = 0x00000000, r1   = 0xbe9a5be0
r2   = 0x00000000, r3   = 0x00000001
r4   = 0xbe9a5be0, r5   = 0x00812414
r6   = 0x00812720, r7   = 0x00000000
r8   = 0x00000000, r9   = 0x000d3b48
r10  = 0x00000001, fp   = 0xbe9a5c68
ip   = 0xb3d66da0, sp   = 0xbe9a59f0
lr   = 0xb3781373, pc   = 0xb36c6bdc
cpsr = 0x28000030

Memory Information
MemTotal:   797320 KB
MemFree:    114200 KB
Buffers:     53704 KB
Cached:     163308 KB
VmPeak:     212928 KB
VmSize:     163144 KB
VmLck:           0 KB
VmHWM:       69728 KB
VmRSS:       69728 KB
VmData:      80036 KB
VmStk:         136 KB
VmExe:          32 KB
VmLib:       50408 KB
VmPTE:         182 KB
VmSwap:          0 KB

Maps Information
00008000 00010000 r-xp /usr/bin/launchpad_preloading_preinitializing_daemon
00018000 000dc000 rw-p [heap]
000dc000 00b4d000 rw-p [heap]
af9b2000 af9b4000 r-xp /usr/lib/evas/modules/loaders/png/linux-gnueabi-armv7l-1.7.99/module.so
af9bc000 af9c1000 r-xp /usr/lib/libhaptic-module.so
b1c83000 b1cce000 r-xp /usr/lib/libGLESv1_CM.so.1.1
b1cd7000 b1ce1000 r-xp /usr/lib/evas/modules/engines/software_generic/linux-gnueabi-armv7l-1.7.99/module.so
b1ce9000 b1d11000 r-xp /usr/lib/evas/modules/engines/gl_x11/linux-gnueabi-armv7l-1.7.99/module.so
b1d39000 b1d45000 r-xp /usr/lib/libtzsvc.so.0.0.1
b1d52000 b1d78000 r-xp /usr/lib/libzmq.so.3.0.0
b1d82000 b1d8b000 r-xp /usr/lib/libpims-ipc.so.0.0.30
b1d93000 b1d95000 r-xp /usr/lib/libemail-network.so.1.1.0
b1d9d000 b1db6000 r-xp /usr/lib/libaccounts-svc.so.0.2.66
b1dbe000 b1e68000 r-xp /usr/lib/libuw-imap-toolkit.so.0.0.0
b1e76000 b1e7a000 r-xp /usr/lib/libss-client.so.1.0.0
b1e82000 b1e84000 r-xp /usr/lib/libcamsrcjpegenc.so.0.0.0
b1e8c000 b1e95000 r-xp /usr/lib/libmsg_vobject.so
b1e9e000 b1ea8000 r-xp /usr/lib/libdrm-client.so.0.0.1
b1eb0000 b1f22000 r-xp /usr/lib/libcontacts-service2.so.0.9.114.7
b1f41000 b1f5a000 r-xp /usr/lib/libmsg_plugin_manager.so
b1f63000 b1f9c000 r-xp /usr/lib/libmsg_framework_handler.so
b1fa5000 b1fd9000 r-xp /usr/lib/libmsg_transaction_proxy.so
b1fe2000 b2022000 r-xp /usr/lib/libmsg_utils.so
b2023000 b2032000 r-xp /usr/lib/libemail-common-use.so.1.1.0
b203b000 b20b6000 r-xp /usr/lib/libemail-core.so.1.1.0
b20c6000 b210f000 r-xp /usr/lib/libemail-storage.so.1.1.0
b2118000 b2125000 r-xp /usr/lib/libemail-ipc.so.1.1.0
b212d000 b2133000 r-xp /usr/lib/libshortcut.so.0.0.1
b213c000 b2142000 r-xp /usr/lib/libbadge.so.0.0.1
b214a000 b2150000 r-xp /usr/lib/libcapi-appfw-app-manager.so.0.1.0
b2158000 b216a000 r-xp /usr/lib/libmmfile_utils.so.0.0.0
b2172000 b2177000 r-xp /usr/lib/libmmffile.so.0.0.0
b217f000 b21e3000 r-xp /usr/lib/libmmfcamcorder.so.0.0.0
b21f0000 b2204000 r-xp /usr/lib/libnetwork.so.0.0.0
b220d000 b2215000 r-xp /usr/lib/libpush.so.0.2.12
b221d000 b2238000 r-xp /usr/lib/libmsg_mapi.so.0.1.0
b2241000 b2259000 r-xp /usr/lib/libemail-api.so.1.1.0
b2261000 b227f000 r-xp /usr/lib/osp/libosp-shell-core.so.1.2.2.1
b2288000 b22a2000 r-xp /usr/lib/osp/libosp-json.so.1.2.2.0
b22ac000 b22b1000 r-xp /usr/lib/libcapi-media-metadata-extractor.so
b22b9000 b22be000 r-xp /usr/lib/libcapi-media-recorder.so.0.1.3
b22c6000 b22d1000 r-xp /usr/lib/libcapi-media-camera.so.0.1.4
b22d9000 b22dc000 r-xp /usr/lib/libcapi-media-sound-manager.so.0.1.1
b22e4000 b22f2000 r-xp /usr/lib/libcapi-media-player.so.0.1.1
b22fa000 b231b000 r-xp /usr/lib/libopencore-amrnb.so.0.0.2
b2324000 b2328000 r-xp /usr/lib/libogg.so.0.7.1
b2330000 b2352000 r-xp /usr/lib/libvorbis.so.0.4.3
b235a000 b235e000 r-xp /usr/lib/libcapi-media-audio-io.so.0.2.0
b2366000 b237a000 r-xp /usr/lib/libwifi-direct.so.0.0
b2382000 b238a000 r-xp /usr/lib/libcapi-network-tethering.so.0.1.0
b238b000 b2394000 r-xp /usr/lib/libcapi-network-connection.so.0.1.3_18
b239c000 b23e9000 r-xp /usr/lib/osp/libosp-messaging.so.1.2.2.0
b23f3000 b24e9000 r-xp /usr/lib/osp/libosp-media.so.1.2.2.0
b24fc000 b25c1000 r-xp /usr/lib/osp/libosp-net.so.1.2.2.0
b25cf000 b25ec000 r-xp /usr/lib/osp/libosp-image.so.1.2.2.0
b25f5000 b25f8000 r-xp /usr/lib/bufmgr/libtbm_exynos4412.so.0.0.0
b2607000 b2679000 r-xp /opt/usr/apps/X4TuAhqX38/bin/TizenProject.exe
b2686000 b26f8000 r-xp /usr/lib/libosp-env-config.so.1.2.2.1
b2700000 b273a000 r-xp /usr/lib/libpulsecommon-0.9.23.so
b2743000 b2747000 r-xp /usr/lib/libmmfsoundcommon.so.0.0.0
b274f000 b2780000 r-xp /usr/lib/libpulse.so.0.12.4
b2788000 b27eb000 r-xp /usr/lib/libasound.so.2.0.0
b27f5000 b27f8000 r-xp /usr/lib/libpulse-simple.so.0.0.3
b2800000 b2804000 r-xp /usr/lib/libascenario-0.2.so.0.0.0
b280d000 b282a000 r-xp /usr/lib/libavsysaudio.so.0.0.1
b2832000 b2840000 r-xp /usr/lib/libmmfsound.so.0.1.0
b2848000 b28e4000 r-xp /usr/lib/libgstreamer-0.10.so.0.30.0
b28f0000 b2931000 r-xp /usr/lib/libgstbase-0.10.so.0.30.0
b293a000 b2943000 r-xp /usr/lib/libgstapp-0.10.so.0.25.0
b294b000 b2958000 r-xp /usr/lib/libgstinterfaces-0.10.so.0.25.0
b2961000 b2967000 r-xp /usr/lib/libUMP.so
b296f000 b2972000 r-xp /usr/lib/libmm_ta.so.0.0.0
b297a000 b2989000 r-xp /usr/lib/libICE.so.6.3.0
b2993000 b2998000 r-xp /usr/lib/libSM.so.6.0.1
b29a0000 b29a1000 r-xp /usr/lib/libmmfkeysound.so.0.0.0
b29a9000 b29b1000 r-xp /usr/lib/libmmfcommon.so.0.0.0
b29b9000 b29c1000 r-xp /usr/lib/libaudio-session-mgr.so.0.0.0
b29cc000 b29cf000 r-xp /usr/lib/libmmfsession.so.0.0.0
b29d7000 b2a1b000 r-xp /usr/lib/libmmfplayer.so.0.0.0
b2a24000 b2a37000 r-xp /usr/lib/libEGL_platform.so
b2a40000 b2b17000 r-xp /usr/lib/libMali.so
b2b22000 b2b28000 r-xp /usr/lib/libxcb-render.so.0.0.0
b2b30000 b2b31000 r-xp /usr/lib/libxcb-shm.so.0.0.0
b2b3a000 b2b78000 r-xp /usr/lib/libGLESv2.so.2.0
b2b80000 b2bcb000 r-xp /usr/lib/libtiff.so.5.1.0
b2bd6000 b2bff000 r-xp /usr/lib/libturbojpeg.so
b2c18000 b2c1e000 r-xp /usr/lib/libmmutil_imgp.so.0.0.0
b2c26000 b2c2c000 r-xp /usr/lib/libgif.so.4.1.6
b2c34000 b2c56000 r-xp /usr/lib/libavutil.so.51.73.101
b2c65000 b2c93000 r-xp /usr/lib/libswscale.so.2.1.101
b2c9c000 b2f93000 r-xp /usr/lib/libavcodec.so.54.59.100
b32ba000 b32d3000 r-xp /usr/lib/libpng12.so.0.50.0
b32dc000 b32e2000 r-xp /usr/lib/libfeedback.so.0.1.4
b32ea000 b32f6000 r-xp /usr/lib/libtts.so
b32fe000 b3315000 r-xp /usr/lib/libEGL.so.1.4
b331e000 b33d5000 r-xp /usr/lib/libcairo.so.2.11200.12
b33df000 b33f9000 r-xp /usr/lib/osp/libosp-image-core.so.1.2.2.0
b3402000 b3cfd000 r-xp /usr/lib/osp/libosp-uifw.so.1.2.2.1
b3d70000 b3d75000 r-xp /usr/lib/libslp_devman_plugin.so
b3d7e000 b3d81000 r-xp /usr/lib/libsyspopup_caller.so.0.1.0
b3d89000 b3d8d000 r-xp /usr/lib/libsysman.so.0.2.0
b3d95000 b3da6000 r-xp /usr/lib/libsecurity-server-commons.so.1.0.0
b3daf000 b3db1000 r-xp /usr/lib/libsystemd-daemon.so.0.0.1
b3db9000 b3dbb000 r-xp /usr/lib/libdeviced.so.0.1.0
b3dc3000 b3dd9000 r-xp /usr/lib/libpkgmgr_parser.so.0.1.0
b3de1000 b3de3000 r-xp /usr/lib/libpkgmgr_installer_status_broadcast_server.so.0.1.0
b3deb000 b3dee000 r-xp /usr/lib/libpkgmgr_installer_client.so.0.1.0
b3df6000 b3df9000 r-xp /usr/lib/libdevice-node.so.0.1
b3e01000 b3e05000 r-xp /usr/lib/libheynoti.so.0.0.2
b3e0d000 b3e52000 r-xp /usr/lib/libsoup-2.4.so.1.5.0
b3e5b000 b3e70000 r-xp /usr/lib/libsecurity-server-client.so.1.0.1
b3e79000 b3e7d000 r-xp /usr/lib/libcapi-system-info.so.0.2.0
b3e85000 b3e8a000 r-xp /usr/lib/libcapi-system-system-settings.so.0.0.2
b3e92000 b3e93000 r-xp /usr/lib/libcapi-system-power.so.0.1.1
b3e9c000 b3e9f000 r-xp /usr/lib/libcapi-system-device.so.0.1.0
b3ea7000 b3eaa000 r-xp /usr/lib/libcapi-system-runtime-info.so.0.0.3
b3eb3000 b3eb6000 r-xp /usr/lib/libcapi-network-serial.so.0.0.8
b3ebe000 b3ebf000 r-xp /usr/lib/libcapi-content-mime-type.so.0.0.2
b3ec7000 b3ed5000 r-xp /usr/lib/libcapi-appfw-application.so.0.1.0
b3ede000 b3f00000 r-xp /usr/lib/libSLP-tapi.so.0.0.0
b3f08000 b3f0b000 r-xp /usr/lib/libuuid.so.1.3.0
b3f14000 b3f32000 r-xp /usr/lib/libpkgmgr-info.so.0.0.17
b3f3a000 b3f51000 r-xp /usr/lib/libpkgmgr-client.so.0.1.68
b3f5a000 b3f5b000 r-xp /usr/lib/libpmapi.so.1.2
b3f63000 b3f6b000 r-xp /usr/lib/libminizip.so.1.0.0
b3f73000 b3f7e000 r-xp /usr/lib/libmessage-port.so.1.2.2.1
b3f86000 b405e000 r-xp /usr/lib/libxml2.so.2.7.8
b406b000 b4089000 r-xp /usr/lib/libpcre.so.0.0.1
b4091000 b4094000 r-xp /usr/lib/libiniparser.so.0
b409d000 b40a1000 r-xp /usr/lib/libhaptic.so.0.1
b40a9000 b40b4000 r-xp /usr/lib/libcryptsvc.so.0.0.1
b40c1000 b40c6000 r-xp /usr/lib/libdevman.so.0.1
b40cf000 b40d3000 r-xp /usr/lib/libchromium.so.1.0
b40db000 b40e1000 r-xp /usr/lib/libappsvc.so.0.1.0
b40e9000 b40ea000 r-xp /usr/lib/osp/libappinfo.so.1.2.2.1
b40fa000 b40fc000 r-xp /opt/usr/apps/X4TuAhqX38/bin/TizenProject
b4104000 b410a000 r-xp /usr/lib/libalarm.so.0.0.0
b4113000 b4125000 r-xp /usr/lib/libprivacy-manager-client.so.0.0.5
b412d000 b442c000 r-xp /usr/lib/osp/libosp-appfw.so.1.2.2.1
b4453000 b445d000 r-xp /lib/libnss_files-2.13.so
b4466000 b446f000 r-xp /lib/libnss_nis-2.13.so
b4478000 b4489000 r-xp /lib/libnsl-2.13.so
b4494000 b449a000 r-xp /lib/libnss_compat-2.13.so
b44a3000 b44ac000 r-xp /usr/lib/libcapi-security-privilege-manager.so.0.0.3
b47d4000 b47e5000 r-xp /usr/lib/libcom-core.so.0.0.1
b47ed000 b47ef000 r-xp /usr/lib/libdri2.so.0.0.0
b47f7000 b47ff000 r-xp /usr/lib/libdrm.so.2.4.0
b4807000 b480b000 r-xp /usr/lib/libtbm.so.1.0.0
b4813000 b4816000 r-xp /usr/lib/libXv.so.1.0.0
b481e000 b48e9000 r-xp /usr/lib/libscim-1.0.so.8.2.3
b48ff000 b490f000 r-xp /usr/lib/libnotification.so.0.1.0
b4917000 b493b000 r-xp /usr/lib/ecore/immodules/libisf-imf-module.so
b4944000 b4954000 r-xp /lib/libresolv-2.13.so
b4958000 b495a000 r-xp /usr/lib/libgmodule-2.0.so.0.3200.3
b4962000 b4ab5000 r-xp /usr/lib/libcrypto.so.1.0.0
b4ad3000 b4b1f000 r-xp /usr/lib/libssl.so.1.0.0
b4b2b000 b4b57000 r-xp /usr/lib/libidn.so.11.5.44
b4b60000 b4b6a000 r-xp /usr/lib/libcares.so.2.0.0
b4b72000 b4b89000 r-xp /lib/libexpat.so.1.5.2
b4b93000 b4bb7000 r-xp /usr/lib/libicule.so.48.1
b4bc0000 b4bc8000 r-xp /usr/lib/libsf_common.so
b4bd0000 b4c6b000 r-xp /usr/lib/libstdc++.so.6.0.14
b4c7e000 b4d5b000 r-xp /usr/lib/libgio-2.0.so.0.3200.3
b4d66000 b4d8b000 r-xp /usr/lib/libexif.so.12.3.3
b4d9f000 b4da9000 r-xp /usr/lib/libethumb.so.1.7.99
b4db1000 b4df5000 r-xp /usr/lib/libsndfile.so.1.0.25
b4e03000 b4e05000 r-xp /usr/lib/libctxdata.so.0.0.0
b4e0d000 b4e1b000 r-xp /usr/lib/libremix.so.0.0.0
b4e23000 b4e24000 r-xp /usr/lib/libecore_imf_evas.so.1.7.99
b4e2c000 b4e45000 r-xp /usr/lib/liblua-5.1.so
b4e4e000 b4e55000 r-xp /usr/lib/libembryo.so.1.7.99
b4e5e000 b4e61000 r-xp /usr/lib/libecore_input_evas.so.1.7.99
b4e69000 b4ea6000 r-xp /usr/lib/libcurl.so.4.3.0
b4eb0000 b4eb4000 r-xp /usr/lib/libecore_ipc.so.1.7.99
b4ebd000 b4f27000 r-xp /usr/lib/libpixman-1.so.0.28.2
b4f34000 b4f58000 r-xp /usr/lib/libfontconfig.so.1.5.0
b4f61000 b4fbd000 r-xp /usr/lib/libharfbuzz.so.0.907.0
b4fcf000 b4fe3000 r-xp /usr/lib/libfribidi.so.0.3.1
b4feb000 b5040000 r-xp /usr/lib/libfreetype.so.6.8.1
b504b000 b506f000 r-xp /usr/lib/libjpeg.so.8.0.2
b5087000 b509e000 r-xp /lib/libz.so.1.2.5
b50a6000 b50b3000 r-xp /usr/lib/libsensor.so.1.1.0
b50be000 b50c0000 r-xp /usr/lib/libapp-checker.so.0.1.0
b50c8000 b50ce000 r-xp /usr/lib/libxdgmime.so.1.1.0
b61e5000 b62cd000 r-xp /usr/lib/libicuuc.so.48.1
b62da000 b63fa000 r-xp /usr/lib/libicui18n.so.48.1
b6408000 b640b000 r-xp /usr/lib/libSLP-db-util.so.0.1.0
b6413000 b641c000 r-xp /usr/lib/libvconf.so.0.2.45
b6424000 b6432000 r-xp /usr/lib/libail.so.0.1.0
b643a000 b6452000 r-xp /usr/lib/libdbus-glib-1.so.2.2.2
b6453000 b6458000 r-xp /usr/lib/libffi.so.5.0.10
b6460000 b6461000 r-xp /usr/lib/libgthread-2.0.so.0.3200.3
b6469000 b6473000 r-xp /usr/lib/libXext.so.6.4.0
b647c000 b647f000 r-xp /usr/lib/libXtst.so.6.1.0
b6487000 b648d000 r-xp /usr/lib/libXrender.so.1.3.0
b6495000 b649b000 r-xp /usr/lib/libXrandr.so.2.2.0
b64a3000 b64a4000 r-xp /usr/lib/libXinerama.so.1.0.0
b64ad000 b64b6000 r-xp /usr/lib/libXi.so.6.1.0
b64be000 b64c1000 r-xp /usr/lib/libXfixes.so.3.1.0
b64c9000 b64cb000 r-xp /usr/lib/libXgesture.so.7.0.0
b64d3000 b64d5000 r-xp /usr/lib/libXcomposite.so.1.0.0
b64dd000 b64de000 r-xp /usr/lib/libXdamage.so.1.1.0
b64e7000 b64ee000 r-xp /usr/lib/libXcursor.so.1.0.2
b64f6000 b64fe000 r-xp /usr/lib/libemotion.so.1.7.99
b6506000 b6521000 r-xp /usr/lib/libecore_con.so.1.7.99
b652a000 b652f000 r-xp /usr/lib/libecore_imf.so.1.7.99
b6538000 b6540000 r-xp /usr/lib/libethumb_client.so.1.7.99
b6548000 b654a000 r-xp /usr/lib/libefreet_trash.so.1.7.99
b6552000 b6556000 r-xp /usr/lib/libefreet_mime.so.1.7.99
b655f000 b6575000 r-xp /usr/lib/libefreet.so.1.7.99
b657f000 b6588000 r-xp /usr/lib/libedbus.so.1.7.99
b6590000 b6595000 r-xp /usr/lib/libecore_fb.so.1.7.99
b659e000 b65fa000 r-xp /usr/lib/libedje.so.1.7.99
b6604000 b661b000 r-xp /usr/lib/libecore_input.so.1.7.99
b6636000 b663b000 r-xp /usr/lib/libecore_file.so.1.7.99
b6643000 b6660000 r-xp /usr/lib/libecore_evas.so.1.7.99
b6669000 b66a8000 r-xp /usr/lib/libeina.so.1.7.99
b66b1000 b6760000 r-xp /usr/lib/libevas.so.1.7.99
b6782000 b6795000 r-xp /usr/lib/libeet.so.1.7.99
b679e000 b6808000 r-xp /lib/libm-2.13.so
b6814000 b681b000 r-xp /usr/lib/libutilX.so.1.1.0
b6823000 b6828000 r-xp /usr/lib/libappcore-common.so.1.1
b6830000 b683b000 r-xp /usr/lib/libaul.so.0.1.0
b6844000 b6878000 r-xp /usr/lib/libgobject-2.0.so.0.3200.3
b6881000 b68b1000 r-xp /usr/lib/libecore_x.so.1.7.99
b68ba000 b68cf000 r-xp /usr/lib/libecore.so.1.7.99
b68e6000 b6a06000 r-xp /usr/lib/libelementary.so.1.7.99
b6a19000 b6a1c000 r-xp /lib/libattr.so.1.1.0
b6a24000 b6a26000 r-xp /usr/lib/libXau.so.6.0.0
b6a2e000 b6a34000 r-xp /lib/librt-2.13.so
b6a3d000 b6a45000 r-xp /lib/libcrypt-2.13.so
b6a75000 b6a78000 r-xp /lib/libcap.so.2.21
b6a80000 b6a82000 r-xp /usr/lib/libiri.so
b6a8a000 b6a9f000 r-xp /usr/lib/libxcb.so.1.1.0
b6aa7000 b6ab2000 r-xp /lib/libunwind.so.8.0.1
b6ae0000 b6bfd000 r-xp /lib/libc-2.13.so
b6c0b000 b6c14000 r-xp /lib/libgcc_s-4.5.3.so.1
b6c1c000 b6c1f000 r-xp /usr/lib/libsmack.so.1.0.0
b6c27000 b6c53000 r-xp /usr/lib/libdbus-1.so.3.7.2
b6c5c000 b6c60000 r-xp /usr/lib/libbundle.so.0.1.22
b6c68000 b6c6a000 r-xp /lib/libdl-2.13.so
b6c73000 b6d4d000 r-xp /usr/lib/libglib-2.0.so.0.3200.3
b6d56000 b6dc0000 r-xp /usr/lib/libsqlite3.so.0.8.6
b6dca000 b6dd7000 r-xp /usr/lib/libprivilege-control.so.0.0.2
b6de0000 b6ec6000 r-xp /usr/lib/libX11.so.6.3.0
b6ed1000 b6ee5000 r-xp /lib/libpthread-2.13.so
b6ef5000 b6ef9000 r-xp /usr/lib/libappcore-efl.so.1.1
b6f02000 b6f03000 r-xp /usr/lib/libdlog.so.0.0.0
b6f0b000 b6f0f000 r-xp /usr/lib/libsys-assert.so
b6f17000 b6f34000 r-xp /lib/ld-2.13.so
be987000 be9a8000 rwxp [stack]
End of Maps Information

Callstack Information (PID:25797)
Call Stack Count: 45
 0: Tizen::Ui::_ControlImpl::GetFullScreenSizeInfo() + 0x53 (0xb36c6bdc) [/usr/lib/osp/libosp-uifw.so] + 0x2c4bdc
 1: (0xb3781373) [/usr/lib/osp/libosp-uifw.so] + 0x37f373
 2: Tizen::Ui::Controls::ScrollPanel::Construct(Tizen::Graphics::Rectangle const&, Tizen::Ui::Controls::ScrollPanelScrollDirection, bool) + 0x12 (0xb377fdeb) [/usr/lib/osp/libosp-uifw.so] + 0x37ddeb
 3: Tizen::Ui::Controls::ScrollPanel::Construct(Tizen::Graphics::Rectangle const&) + 0xa (0xb377ff3b) [/usr/lib/osp/libosp-uifw.so] + 0x37df3b
 4: PartnerSearchItem::OnActionPerformed(Tizen::Ui::Control const&, int) + 0x21c (0xb2650e60) [/opt/apps/X4TuAhqX38/bin/TizenProject.exe] + 0x49e60
 5: non-virtual thunk to PartnerSearchItem::OnActionPerformed(Tizen::Ui::Control const&, int) + 0x3c (0xb26512e4) [/opt/apps/X4TuAhqX38/bin/TizenProject.exe] + 0x4a2e4
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
