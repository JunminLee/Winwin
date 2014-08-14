S/W Version Information
Model: Ref.Device-PQ
Tizen-Version: 2.2.1
Build-Number: Tizen_Ref.Device-PQ_20131118.1124
Build-Date: 2013.11.18 11:24:59

Crash Information
Process Name: TizenProject
PID: 10869
Date: 2014-08-14 11:36:07(GMT+0900)
Executable File Path: /opt/apps/X4TuAhqX38/bin/TizenProject
This process is multi-thread process
pid=10869 tid=10869
Signal: 11
      (SIGSEGV)
      si_code: -6
      signal sent by tkill (sent by pid 10869, uid 5000)

Register Information
r0   = 0xbe82eb90, r1   = 0x00000050
r2   = 0xb44af330, r3   = 0x00007cd4
r4   = 0xbe82eb90, r5   = 0xb3dd7d70
r6   = 0x00000050, r7   = 0xa89343b0
r8   = 0xbe82eefc, r9   = 0xbe82f1e0
r10  = 0xb3dd7d70, fp   = 0xbe82ebf0
ip   = 0xb3dde1d0, sp   = 0xbe82eb30
lr   = 0xb3aa1499, pc   = 0xb3aa149c
cpsr = 0x88000030

Memory Information
MemTotal:   797320 KB
MemFree:    186456 KB
Buffers:     79980 KB
Cached:     177300 KB
VmPeak:     283368 KB
VmSize:     214368 KB
VmLck:           0 KB
VmHWM:       96652 KB
VmRSS:       96652 KB
VmData:     131112 KB
VmStk:         136 KB
VmExe:          32 KB
VmLib:       50460 KB
VmPTE:         232 KB
VmSwap:          0 KB

Maps Information
00008000 00010000 r-xp /usr/bin/launchpad_preloading_preinitializing_daemon
00018000 000dc000 rw-p [heap]
000dc000 00275000 rw-p [heap]
aebfd000 aec0e000 r-xp /usr/lib/scim-1.0/1.4.0/IMEngine/socket.so
afa1a000 afa1c000 r-xp /usr/lib/evas/modules/loaders/png/linux-gnueabi-armv7l-1.7.99/module.so
afa24000 afa29000 r-xp /usr/lib/scim-1.0/1.4.0/Config/socket.so
afa31000 afa36000 r-xp /usr/lib/libhaptic-module.so
b1d00000 b1d4b000 r-xp /usr/lib/libGLESv1_CM.so.1.1
b1d54000 b1d5e000 r-xp /usr/lib/evas/modules/engines/software_generic/linux-gnueabi-armv7l-1.7.99/module.so
b1d66000 b1d8e000 r-xp /usr/lib/evas/modules/engines/gl_x11/linux-gnueabi-armv7l-1.7.99/module.so
b1db6000 b1dc2000 r-xp /usr/lib/libtzsvc.so.0.0.1
b1dcf000 b1df5000 r-xp /usr/lib/libzmq.so.3.0.0
b1dff000 b1e08000 r-xp /usr/lib/libpims-ipc.so.0.0.30
b1e10000 b1e12000 r-xp /usr/lib/libemail-network.so.1.1.0
b1e1a000 b1e33000 r-xp /usr/lib/libaccounts-svc.so.0.2.66
b1e3b000 b1ee5000 r-xp /usr/lib/libuw-imap-toolkit.so.0.0.0
b1ef3000 b1ef7000 r-xp /usr/lib/libss-client.so.1.0.0
b1eff000 b1f01000 r-xp /usr/lib/libcamsrcjpegenc.so.0.0.0
b1f09000 b1f12000 r-xp /usr/lib/libmsg_vobject.so
b1f1b000 b1f25000 r-xp /usr/lib/libdrm-client.so.0.0.1
b1f2d000 b1f9f000 r-xp /usr/lib/libcontacts-service2.so.0.9.114.7
b1fbe000 b1fd7000 r-xp /usr/lib/libmsg_plugin_manager.so
b1fe0000 b2019000 r-xp /usr/lib/libmsg_framework_handler.so
b2022000 b2056000 r-xp /usr/lib/libmsg_transaction_proxy.so
b205f000 b209f000 r-xp /usr/lib/libmsg_utils.so
b20a0000 b20af000 r-xp /usr/lib/libemail-common-use.so.1.1.0
b20b8000 b2133000 r-xp /usr/lib/libemail-core.so.1.1.0
b2143000 b218c000 r-xp /usr/lib/libemail-storage.so.1.1.0
b2195000 b21a2000 r-xp /usr/lib/libemail-ipc.so.1.1.0
b21aa000 b21b0000 r-xp /usr/lib/libshortcut.so.0.0.1
b21b9000 b21bf000 r-xp /usr/lib/libbadge.so.0.0.1
b21c7000 b21cd000 r-xp /usr/lib/libcapi-appfw-app-manager.so.0.1.0
b21d5000 b21e7000 r-xp /usr/lib/libmmfile_utils.so.0.0.0
b21ef000 b21f4000 r-xp /usr/lib/libmmffile.so.0.0.0
b21fc000 b2260000 r-xp /usr/lib/libmmfcamcorder.so.0.0.0
b226d000 b2281000 r-xp /usr/lib/libnetwork.so.0.0.0
b228a000 b2292000 r-xp /usr/lib/libpush.so.0.2.12
b229a000 b22b5000 r-xp /usr/lib/libmsg_mapi.so.0.1.0
b22be000 b22d6000 r-xp /usr/lib/libemail-api.so.1.1.0
b22de000 b22fc000 r-xp /usr/lib/osp/libosp-shell-core.so.1.2.2.1
b2305000 b231f000 r-xp /usr/lib/osp/libosp-json.so.1.2.2.0
b2329000 b232e000 r-xp /usr/lib/libcapi-media-metadata-extractor.so
b2336000 b233b000 r-xp /usr/lib/libcapi-media-recorder.so.0.1.3
b2343000 b234e000 r-xp /usr/lib/libcapi-media-camera.so.0.1.4
b2356000 b2359000 r-xp /usr/lib/libcapi-media-sound-manager.so.0.1.1
b2361000 b236f000 r-xp /usr/lib/libcapi-media-player.so.0.1.1
b2377000 b2398000 r-xp /usr/lib/libopencore-amrnb.so.0.0.2
b23a1000 b23a5000 r-xp /usr/lib/libogg.so.0.7.1
b23ad000 b23cf000 r-xp /usr/lib/libvorbis.so.0.4.3
b23d7000 b23db000 r-xp /usr/lib/libcapi-media-audio-io.so.0.2.0
b23e3000 b23f7000 r-xp /usr/lib/libwifi-direct.so.0.0
b23ff000 b2407000 r-xp /usr/lib/libcapi-network-tethering.so.0.1.0
b2408000 b2411000 r-xp /usr/lib/libcapi-network-connection.so.0.1.3_18
b2419000 b2466000 r-xp /usr/lib/osp/libosp-messaging.so.1.2.2.0
b2470000 b2566000 r-xp /usr/lib/osp/libosp-media.so.1.2.2.0
b2579000 b263e000 r-xp /usr/lib/osp/libosp-net.so.1.2.2.0
b264c000 b2669000 r-xp /usr/lib/osp/libosp-image.so.1.2.2.0
b2678000 b267b000 r-xp /usr/lib/bufmgr/libtbm_exynos4412.so.0.0.0
b2684000 b26ed000 r-xp /opt/usr/apps/X4TuAhqX38/bin/TizenProject.exe
b26f9000 b276b000 r-xp /usr/lib/libosp-env-config.so.1.2.2.1
b2773000 b27ad000 r-xp /usr/lib/libpulsecommon-0.9.23.so
b27b6000 b27ba000 r-xp /usr/lib/libmmfsoundcommon.so.0.0.0
b27c2000 b27f3000 r-xp /usr/lib/libpulse.so.0.12.4
b27fb000 b285e000 r-xp /usr/lib/libasound.so.2.0.0
b2868000 b286b000 r-xp /usr/lib/libpulse-simple.so.0.0.3
b2873000 b2877000 r-xp /usr/lib/libascenario-0.2.so.0.0.0
b2880000 b289d000 r-xp /usr/lib/libavsysaudio.so.0.0.1
b28a5000 b28b3000 r-xp /usr/lib/libmmfsound.so.0.1.0
b28bb000 b2957000 r-xp /usr/lib/libgstreamer-0.10.so.0.30.0
b2963000 b29a4000 r-xp /usr/lib/libgstbase-0.10.so.0.30.0
b29ad000 b29b6000 r-xp /usr/lib/libgstapp-0.10.so.0.25.0
b29be000 b29cb000 r-xp /usr/lib/libgstinterfaces-0.10.so.0.25.0
b29d4000 b29da000 r-xp /usr/lib/libUMP.so
b29e2000 b29e5000 r-xp /usr/lib/libmm_ta.so.0.0.0
b29ed000 b29fc000 r-xp /usr/lib/libICE.so.6.3.0
b2a06000 b2a0b000 r-xp /usr/lib/libSM.so.6.0.1
b2a13000 b2a14000 r-xp /usr/lib/libmmfkeysound.so.0.0.0
b2a1c000 b2a24000 r-xp /usr/lib/libmmfcommon.so.0.0.0
b2a2c000 b2a34000 r-xp /usr/lib/libaudio-session-mgr.so.0.0.0
b2a3f000 b2a42000 r-xp /usr/lib/libmmfsession.so.0.0.0
b2a4a000 b2a8e000 r-xp /usr/lib/libmmfplayer.so.0.0.0
b2a97000 b2aaa000 r-xp /usr/lib/libEGL_platform.so
b2ab3000 b2b8a000 r-xp /usr/lib/libMali.so
b2b95000 b2b9b000 r-xp /usr/lib/libxcb-render.so.0.0.0
b2ba3000 b2ba4000 r-xp /usr/lib/libxcb-shm.so.0.0.0
b2bad000 b2beb000 r-xp /usr/lib/libGLESv2.so.2.0
b2bf3000 b2c3e000 r-xp /usr/lib/libtiff.so.5.1.0
b2c49000 b2c72000 r-xp /usr/lib/libturbojpeg.so
b2c8b000 b2c91000 r-xp /usr/lib/libmmutil_imgp.so.0.0.0
b2c99000 b2c9f000 r-xp /usr/lib/libgif.so.4.1.6
b2ca7000 b2cc9000 r-xp /usr/lib/libavutil.so.51.73.101
b2cd8000 b2d06000 r-xp /usr/lib/libswscale.so.2.1.101
b2d0f000 b3006000 r-xp /usr/lib/libavcodec.so.54.59.100
b332d000 b3346000 r-xp /usr/lib/libpng12.so.0.50.0
b334f000 b3355000 r-xp /usr/lib/libfeedback.so.0.1.4
b335d000 b3369000 r-xp /usr/lib/libtts.so
b3371000 b3388000 r-xp /usr/lib/libEGL.so.1.4
b3391000 b3448000 r-xp /usr/lib/libcairo.so.2.11200.12
b3452000 b346c000 r-xp /usr/lib/osp/libosp-image-core.so.1.2.2.0
b3475000 b3d70000 r-xp /usr/lib/osp/libosp-uifw.so.1.2.2.1
b3de3000 b3de8000 r-xp /usr/lib/libslp_devman_plugin.so
b3df1000 b3df4000 r-xp /usr/lib/libsyspopup_caller.so.0.1.0
b3dfc000 b3e00000 r-xp /usr/lib/libsysman.so.0.2.0
b3e08000 b3e19000 r-xp /usr/lib/libsecurity-server-commons.so.1.0.0
b3e22000 b3e24000 r-xp /usr/lib/libsystemd-daemon.so.0.0.1
b3e2c000 b3e2e000 r-xp /usr/lib/libdeviced.so.0.1.0
b3e36000 b3e4c000 r-xp /usr/lib/libpkgmgr_parser.so.0.1.0
b3e54000 b3e56000 r-xp /usr/lib/libpkgmgr_installer_status_broadcast_server.so.0.1.0
b3e5e000 b3e61000 r-xp /usr/lib/libpkgmgr_installer_client.so.0.1.0
b3e69000 b3e6c000 r-xp /usr/lib/libdevice-node.so.0.1
b3e74000 b3e78000 r-xp /usr/lib/libheynoti.so.0.0.2
b3e80000 b3ec5000 r-xp /usr/lib/libsoup-2.4.so.1.5.0
b3ece000 b3ee3000 r-xp /usr/lib/libsecurity-server-client.so.1.0.1
b3eec000 b3ef0000 r-xp /usr/lib/libcapi-system-info.so.0.2.0
b3ef8000 b3efd000 r-xp /usr/lib/libcapi-system-system-settings.so.0.0.2
b3f05000 b3f06000 r-xp /usr/lib/libcapi-system-power.so.0.1.1
b3f0f000 b3f12000 r-xp /usr/lib/libcapi-system-device.so.0.1.0
b3f1a000 b3f1d000 r-xp /usr/lib/libcapi-system-runtime-info.so.0.0.3
b3f26000 b3f29000 r-xp /usr/lib/libcapi-network-serial.so.0.0.8
b3f31000 b3f32000 r-xp /usr/lib/libcapi-content-mime-type.so.0.0.2
b3f3a000 b3f48000 r-xp /usr/lib/libcapi-appfw-application.so.0.1.0
b3f51000 b3f73000 r-xp /usr/lib/libSLP-tapi.so.0.0.0
b3f7b000 b3f7e000 r-xp /usr/lib/libuuid.so.1.3.0
b3f87000 b3fa5000 r-xp /usr/lib/libpkgmgr-info.so.0.0.17
b3fad000 b3fc4000 r-xp /usr/lib/libpkgmgr-client.so.0.1.68
b3fcd000 b3fce000 r-xp /usr/lib/libpmapi.so.1.2
b3fd6000 b3fde000 r-xp /usr/lib/libminizip.so.1.0.0
b3fe6000 b3ff1000 r-xp /usr/lib/libmessage-port.so.1.2.2.1
b3ff9000 b40d1000 r-xp /usr/lib/libxml2.so.2.7.8
b40de000 b40fc000 r-xp /usr/lib/libpcre.so.0.0.1
b4104000 b4107000 r-xp /usr/lib/libiniparser.so.0
b4110000 b4114000 r-xp /usr/lib/libhaptic.so.0.1
b411c000 b4127000 r-xp /usr/lib/libcryptsvc.so.0.0.1
b4134000 b4139000 r-xp /usr/lib/libdevman.so.0.1
b4142000 b4146000 r-xp /usr/lib/libchromium.so.1.0
b414e000 b4154000 r-xp /usr/lib/libappsvc.so.0.1.0
b415c000 b415d000 r-xp /usr/lib/osp/libappinfo.so.1.2.2.1
b416d000 b416f000 r-xp /opt/usr/apps/X4TuAhqX38/bin/TizenProject
b4177000 b417d000 r-xp /usr/lib/libalarm.so.0.0.0
b4186000 b4198000 r-xp /usr/lib/libprivacy-manager-client.so.0.0.5
b41a0000 b449f000 r-xp /usr/lib/osp/libosp-appfw.so.1.2.2.1
b44c6000 b44d0000 r-xp /lib/libnss_files-2.13.so
b44d9000 b44e2000 r-xp /lib/libnss_nis-2.13.so
b44eb000 b44fc000 r-xp /lib/libnsl-2.13.so
b4507000 b450d000 r-xp /lib/libnss_compat-2.13.so
b4516000 b451f000 r-xp /usr/lib/libcapi-security-privilege-manager.so.0.0.3
b4847000 b4858000 r-xp /usr/lib/libcom-core.so.0.0.1
b4860000 b4862000 r-xp /usr/lib/libdri2.so.0.0.0
b486a000 b4872000 r-xp /usr/lib/libdrm.so.2.4.0
b487a000 b487e000 r-xp /usr/lib/libtbm.so.1.0.0
b4886000 b4889000 r-xp /usr/lib/libXv.so.1.0.0
b4891000 b495c000 r-xp /usr/lib/libscim-1.0.so.8.2.3
b4972000 b4982000 r-xp /usr/lib/libnotification.so.0.1.0
b498a000 b49ae000 r-xp /usr/lib/ecore/immodules/libisf-imf-module.so
b49b7000 b49c7000 r-xp /lib/libresolv-2.13.so
b49cb000 b49cd000 r-xp /usr/lib/libgmodule-2.0.so.0.3200.3
b49d5000 b4b28000 r-xp /usr/lib/libcrypto.so.1.0.0
b4b46000 b4b92000 r-xp /usr/lib/libssl.so.1.0.0
b4b9e000 b4bca000 r-xp /usr/lib/libidn.so.11.5.44
b4bd3000 b4bdd000 r-xp /usr/lib/libcares.so.2.0.0
b4be5000 b4bfc000 r-xp /lib/libexpat.so.1.5.2
b4c06000 b4c2a000 r-xp /usr/lib/libicule.so.48.1
b4c33000 b4c3b000 r-xp /usr/lib/libsf_common.so
b4c43000 b4cde000 r-xp /usr/lib/libstdc++.so.6.0.14
b4cf1000 b4dce000 r-xp /usr/lib/libgio-2.0.so.0.3200.3
b4dd9000 b4dfe000 r-xp /usr/lib/libexif.so.12.3.3
b4e12000 b4e1c000 r-xp /usr/lib/libethumb.so.1.7.99
b4e24000 b4e68000 r-xp /usr/lib/libsndfile.so.1.0.25
b4e76000 b4e78000 r-xp /usr/lib/libctxdata.so.0.0.0
b4e80000 b4e8e000 r-xp /usr/lib/libremix.so.0.0.0
b4e96000 b4e97000 r-xp /usr/lib/libecore_imf_evas.so.1.7.99
b4e9f000 b4eb8000 r-xp /usr/lib/liblua-5.1.so
b4ec1000 b4ec8000 r-xp /usr/lib/libembryo.so.1.7.99
b4ed1000 b4ed4000 r-xp /usr/lib/libecore_input_evas.so.1.7.99
b4edc000 b4f19000 r-xp /usr/lib/libcurl.so.4.3.0
b4f23000 b4f27000 r-xp /usr/lib/libecore_ipc.so.1.7.99
b4f30000 b4f9a000 r-xp /usr/lib/libpixman-1.so.0.28.2
b4fa7000 b4fcb000 r-xp /usr/lib/libfontconfig.so.1.5.0
b4fd4000 b5030000 r-xp /usr/lib/libharfbuzz.so.0.907.0
b5042000 b5056000 r-xp /usr/lib/libfribidi.so.0.3.1
b505e000 b50b3000 r-xp /usr/lib/libfreetype.so.6.8.1
b50be000 b50e2000 r-xp /usr/lib/libjpeg.so.8.0.2
b50fa000 b5111000 r-xp /lib/libz.so.1.2.5
b5119000 b5126000 r-xp /usr/lib/libsensor.so.1.1.0
b5131000 b5133000 r-xp /usr/lib/libapp-checker.so.0.1.0
b513b000 b5141000 r-xp /usr/lib/libxdgmime.so.1.1.0
b6258000 b6340000 r-xp /usr/lib/libicuuc.so.48.1
b634d000 b646d000 r-xp /usr/lib/libicui18n.so.48.1
b647b000 b647e000 r-xp /usr/lib/libSLP-db-util.so.0.1.0
b6486000 b648f000 r-xp /usr/lib/libvconf.so.0.2.45
b6497000 b64a5000 r-xp /usr/lib/libail.so.0.1.0
b64ad000 b64c5000 r-xp /usr/lib/libdbus-glib-1.so.2.2.2
b64c6000 b64cb000 r-xp /usr/lib/libffi.so.5.0.10
b64d3000 b64d4000 r-xp /usr/lib/libgthread-2.0.so.0.3200.3
b64dc000 b64e6000 r-xp /usr/lib/libXext.so.6.4.0
b64ef000 b64f2000 r-xp /usr/lib/libXtst.so.6.1.0
b64fa000 b6500000 r-xp /usr/lib/libXrender.so.1.3.0
b6508000 b650e000 r-xp /usr/lib/libXrandr.so.2.2.0
b6516000 b6517000 r-xp /usr/lib/libXinerama.so.1.0.0
b6520000 b6529000 r-xp /usr/lib/libXi.so.6.1.0
b6531000 b6534000 r-xp /usr/lib/libXfixes.so.3.1.0
b653c000 b653e000 r-xp /usr/lib/libXgesture.so.7.0.0
b6546000 b6548000 r-xp /usr/lib/libXcomposite.so.1.0.0
b6550000 b6551000 r-xp /usr/lib/libXdamage.so.1.1.0
b655a000 b6561000 r-xp /usr/lib/libXcursor.so.1.0.2
b6569000 b6571000 r-xp /usr/lib/libemotion.so.1.7.99
b6579000 b6594000 r-xp /usr/lib/libecore_con.so.1.7.99
b659d000 b65a2000 r-xp /usr/lib/libecore_imf.so.1.7.99
b65ab000 b65b3000 r-xp /usr/lib/libethumb_client.so.1.7.99
b65bb000 b65bd000 r-xp /usr/lib/libefreet_trash.so.1.7.99
b65c5000 b65c9000 r-xp /usr/lib/libefreet_mime.so.1.7.99
b65d2000 b65e8000 r-xp /usr/lib/libefreet.so.1.7.99
b65f2000 b65fb000 r-xp /usr/lib/libedbus.so.1.7.99
b6603000 b6608000 r-xp /usr/lib/libecore_fb.so.1.7.99
b6611000 b666d000 r-xp /usr/lib/libedje.so.1.7.99
b6677000 b668e000 r-xp /usr/lib/libecore_input.so.1.7.99
b66a9000 b66ae000 r-xp /usr/lib/libecore_file.so.1.7.99
b66b6000 b66d3000 r-xp /usr/lib/libecore_evas.so.1.7.99
b66dc000 b671b000 r-xp /usr/lib/libeina.so.1.7.99
b6724000 b67d3000 r-xp /usr/lib/libevas.so.1.7.99
b67f5000 b6808000 r-xp /usr/lib/libeet.so.1.7.99
b6811000 b687b000 r-xp /lib/libm-2.13.so
b6887000 b688e000 r-xp /usr/lib/libutilX.so.1.1.0
b6896000 b689b000 r-xp /usr/lib/libappcore-common.so.1.1
b68a3000 b68ae000 r-xp /usr/lib/libaul.so.0.1.0
b68b7000 b68eb000 r-xp /usr/lib/libgobject-2.0.so.0.3200.3
b68f4000 b6924000 r-xp /usr/lib/libecore_x.so.1.7.99
b692d000 b6942000 r-xp /usr/lib/libecore.so.1.7.99
b6959000 b6a79000 r-xp /usr/lib/libelementary.so.1.7.99
b6a8c000 b6a8f000 r-xp /lib/libattr.so.1.1.0
b6a97000 b6a99000 r-xp /usr/lib/libXau.so.6.0.0
b6aa1000 b6aa7000 r-xp /lib/librt-2.13.so
b6ab0000 b6ab8000 r-xp /lib/libcrypt-2.13.so
b6ae8000 b6aeb000 r-xp /lib/libcap.so.2.21
b6af3000 b6af5000 r-xp /usr/lib/libiri.so
b6afd000 b6b12000 r-xp /usr/lib/libxcb.so.1.1.0
b6b1a000 b6b25000 r-xp /lib/libunwind.so.8.0.1
b6b53000 b6c70000 r-xp /lib/libc-2.13.so
b6c7e000 b6c87000 r-xp /lib/libgcc_s-4.5.3.so.1
b6c8f000 b6c92000 r-xp /usr/lib/libsmack.so.1.0.0
b6c9a000 b6cc6000 r-xp /usr/lib/libdbus-1.so.3.7.2
b6ccf000 b6cd3000 r-xp /usr/lib/libbundle.so.0.1.22
b6cdb000 b6cdd000 r-xp /lib/libdl-2.13.so
b6ce6000 b6dc0000 r-xp /usr/lib/libglib-2.0.so.0.3200.3
b6dc9000 b6e33000 r-xp /usr/lib/libsqlite3.so.0.8.6
b6e3d000 b6e4a000 r-xp /usr/lib/libprivilege-control.so.0.0.2
b6e53000 b6f39000 r-xp /usr/lib/libX11.so.6.3.0
b6f44000 b6f58000 r-xp /lib/libpthread-2.13.so
b6f68000 b6f6c000 r-xp /usr/lib/libappcore-efl.so.1.1
b6f75000 b6f76000 r-xp /usr/lib/libdlog.so.0.0.0
b6f7e000 b6f82000 r-xp /usr/lib/libsys-assert.so
b6f8a000 b6fa7000 r-xp /lib/ld-2.13.so
be810000 be831000 rwxp [stack]
End of Maps Information

Callstack Information (PID:10869)
Call Stack Count: 32
 0: Tizen::Graphics::Rectangle::Rectangle(Tizen::Graphics::Rectangle const&) + 0xf (0xb3aa149c) [/usr/lib/osp/libosp-uifw.so] + 0x62c49c
 1: JMChattControl::GetImageIndexByPoint(Tizen::Graphics::Point) + 0xa8 (0xb26bd424) [/opt/apps/X4TuAhqX38/bin/TizenProject.exe] + 0x39424
 2: JMChattControl::OnTouchPressed(Tizen::Ui::Control const&, Tizen::Graphics::Point const&, Tizen::Ui::TouchEventInfo const&) + 0xf8 (0xb26bd30c) [/opt/apps/X4TuAhqX38/bin/TizenProject.exe] + 0x3930c
 3: non-virtual thunk to JMChattControl::OnTouchPressed(Tizen::Ui::Control const&, Tizen::Graphics::Point const&, Tizen::Ui::TouchEventInfo const&) + 0x4c (0xb26bd5a0) [/opt/apps/X4TuAhqX38/bin/TizenProject.exe] + 0x395a0
 4: Tizen::Ui::_ControlImpl::CoreTouchEvent::ProcessListener(Tizen::Ui::_TouchInfo const&) + 0x224 (0xb37427fd) [/usr/lib/osp/libosp-uifw.so] + 0x2cd7fd
 5: Tizen::Ui::_ControlImpl::CallOnTouchPressed(Tizen::Ui::_Control const&, Tizen::Ui::_TouchInfo const&) + 0xac (0xb373b8dd) [/usr/lib/osp/libosp-uifw.so] + 0x2c68dd
 6: Tizen::Ui::_ControlImpl::_PropagatedTouchEventListener::OnTouchPressed(Tizen::Ui::_Control const&, Tizen::Ui::_TouchInfo const&) + 0x200 (0xb3743279) [/usr/lib/osp/libosp-uifw.so] + 0x2ce279
 7: Tizen::Ui::_UiTouchEvent::FireListener(Tizen::Ui::_ITouchEventListener const*, Tizen::Ui::_Control const*, bool, bool&) + 0x2de (0xb37a996b) [/usr/lib/osp/libosp-uifw.so] + 0x33496b
 8: Tizen::Ui::_UiTouchEvent::OnEventProcessing(Tizen::Ui::_Control const&, bool&) + 0x62 (0xb37a9e43) [/usr/lib/osp/libosp-uifw.so] + 0x334e43
 9: Tizen::Ui::_UiEvent::ProcessEvent(Tizen::Ui::_Control const&, bool&) + 0x32 (0xb379df53) [/usr/lib/osp/libosp-uifw.so] + 0x328f53
10: Tizen::Ui::_UiEventManager::ProcessBubblingEvent(Tizen::Base::Collection::LinkedListT<Tizen::Base::_HandleT<Tizen::Ui::_Control> > const&, Tizen::Ui::_UiEvent const&, bool&) + 0x78 (0xb379e901) [/usr/lib/osp/libosp-uifw.so] + 0x329901
11: Tizen::Ui::_UiEventManager::ProcessEvent(Tizen::Ui::_UiEvent const&, bool&) + 0x234 (0xb379ebd5) [/usr/lib/osp/libosp-uifw.so] + 0x329bd5
12: Tizen::Ui::_UiEventManager::Fire(Tizen::Ui::_UiEvent const&) + 0x8c (0xb379ecb9) [/usr/lib/osp/libosp-uifw.so] + 0x329cb9
13: Tizen::Ui::_UiEventManager::SendEvent(Tizen::Ui::_UiEvent const&) + 0x6 (0xb379ed4b) [/usr/lib/osp/libosp-uifw.so] + 0x329d4b
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
