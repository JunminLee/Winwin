S/W Version Information
Model: Ref.Device-PQ
Tizen-Version: 2.2.1
Build-Number: Tizen_Ref.Device-PQ_20131118.1124
Build-Date: 2013.11.18 11:24:59

Crash Information
Process Name: TizenProject
PID: 19377
Date: 2014-08-15 02:26:01(GMT+0900)
Executable File Path: /opt/apps/X4TuAhqX38/bin/TizenProject
This process is multi-thread process
pid=19377 tid=19377
Signal: 11
      (SIGSEGV)
      si_code: -6
      signal sent by tkill (sent by pid 19377, uid 5000)

Register Information
r0   = 0xbeebcb90, r1   = 0x00000050
r2   = 0xb4430330, r3   = 0x00007cd4
r4   = 0xbeebcb90, r5   = 0xb3d58d70
r6   = 0x00000050, r7   = 0xaa00f8e0
r8   = 0xbeebcefc, r9   = 0xbeebd1e0
r10  = 0xb3d58d70, fp   = 0xbeebcbf0
ip   = 0xb3d5f1d0, sp   = 0xbeebcb30
lr   = 0xb3a22499, pc   = 0xb3a2249c
cpsr = 0x88000030

Memory Information
MemTotal:   797320 KB
MemFree:     28740 KB
Buffers:      6908 KB
Cached:     265096 KB
VmPeak:     256756 KB
VmSize:     198508 KB
VmLck:           0 KB
VmHWM:       81264 KB
VmRSS:       81264 KB
VmData:     115252 KB
VmStk:         136 KB
VmExe:          32 KB
VmLib:       50460 KB
VmPTE:         206 KB
VmSwap:          0 KB

Maps Information
00008000 00010000 r-xp /usr/bin/launchpad_preloading_preinitializing_daemon
00018000 000dc000 rw-p [heap]
000dc000 00ab9000 rw-p [heap]
a8879000 a887b000 r-xp /usr/lib/evas/modules/loaders/png/linux-gnueabi-armv7l-1.7.99/module.so
aa95c000 aa961000 r-xp /usr/lib/scim-1.0/1.4.0/Config/socket.so
af99f000 af9b0000 r-xp /usr/lib/scim-1.0/1.4.0/IMEngine/socket.so
af9b9000 af9be000 r-xp /usr/lib/libhaptic-module.so
b1c80000 b1ccb000 r-xp /usr/lib/libGLESv1_CM.so.1.1
b1cd4000 b1cde000 r-xp /usr/lib/evas/modules/engines/software_generic/linux-gnueabi-armv7l-1.7.99/module.so
b1ce6000 b1d0e000 r-xp /usr/lib/evas/modules/engines/gl_x11/linux-gnueabi-armv7l-1.7.99/module.so
b1d36000 b1d42000 r-xp /usr/lib/libtzsvc.so.0.0.1
b1d4f000 b1d75000 r-xp /usr/lib/libzmq.so.3.0.0
b1d7f000 b1d88000 r-xp /usr/lib/libpims-ipc.so.0.0.30
b1d90000 b1d92000 r-xp /usr/lib/libemail-network.so.1.1.0
b1d9a000 b1db3000 r-xp /usr/lib/libaccounts-svc.so.0.2.66
b1dbb000 b1e65000 r-xp /usr/lib/libuw-imap-toolkit.so.0.0.0
b1e73000 b1e77000 r-xp /usr/lib/libss-client.so.1.0.0
b1e7f000 b1e81000 r-xp /usr/lib/libcamsrcjpegenc.so.0.0.0
b1e89000 b1e92000 r-xp /usr/lib/libmsg_vobject.so
b1e9b000 b1ea5000 r-xp /usr/lib/libdrm-client.so.0.0.1
b1ead000 b1f1f000 r-xp /usr/lib/libcontacts-service2.so.0.9.114.7
b1f3e000 b1f57000 r-xp /usr/lib/libmsg_plugin_manager.so
b1f60000 b1f99000 r-xp /usr/lib/libmsg_framework_handler.so
b1fa2000 b1fd6000 r-xp /usr/lib/libmsg_transaction_proxy.so
b1fdf000 b201f000 r-xp /usr/lib/libmsg_utils.so
b2020000 b202f000 r-xp /usr/lib/libemail-common-use.so.1.1.0
b2038000 b20b3000 r-xp /usr/lib/libemail-core.so.1.1.0
b20c3000 b210c000 r-xp /usr/lib/libemail-storage.so.1.1.0
b2115000 b2122000 r-xp /usr/lib/libemail-ipc.so.1.1.0
b212a000 b2130000 r-xp /usr/lib/libshortcut.so.0.0.1
b2139000 b213f000 r-xp /usr/lib/libbadge.so.0.0.1
b2147000 b214d000 r-xp /usr/lib/libcapi-appfw-app-manager.so.0.1.0
b2155000 b2167000 r-xp /usr/lib/libmmfile_utils.so.0.0.0
b216f000 b2174000 r-xp /usr/lib/libmmffile.so.0.0.0
b217c000 b21e0000 r-xp /usr/lib/libmmfcamcorder.so.0.0.0
b21ed000 b2201000 r-xp /usr/lib/libnetwork.so.0.0.0
b220a000 b2212000 r-xp /usr/lib/libpush.so.0.2.12
b221a000 b2235000 r-xp /usr/lib/libmsg_mapi.so.0.1.0
b223e000 b2256000 r-xp /usr/lib/libemail-api.so.1.1.0
b225e000 b227c000 r-xp /usr/lib/osp/libosp-shell-core.so.1.2.2.1
b2285000 b229f000 r-xp /usr/lib/osp/libosp-json.so.1.2.2.0
b22a9000 b22ae000 r-xp /usr/lib/libcapi-media-metadata-extractor.so
b22b6000 b22bb000 r-xp /usr/lib/libcapi-media-recorder.so.0.1.3
b22c3000 b22ce000 r-xp /usr/lib/libcapi-media-camera.so.0.1.4
b22d6000 b22d9000 r-xp /usr/lib/libcapi-media-sound-manager.so.0.1.1
b22e1000 b22ef000 r-xp /usr/lib/libcapi-media-player.so.0.1.1
b22f7000 b2318000 r-xp /usr/lib/libopencore-amrnb.so.0.0.2
b2321000 b2325000 r-xp /usr/lib/libogg.so.0.7.1
b232d000 b234f000 r-xp /usr/lib/libvorbis.so.0.4.3
b2357000 b235b000 r-xp /usr/lib/libcapi-media-audio-io.so.0.2.0
b2363000 b2377000 r-xp /usr/lib/libwifi-direct.so.0.0
b237f000 b2387000 r-xp /usr/lib/libcapi-network-tethering.so.0.1.0
b2388000 b2391000 r-xp /usr/lib/libcapi-network-connection.so.0.1.3_18
b2399000 b23e6000 r-xp /usr/lib/osp/libosp-messaging.so.1.2.2.0
b23f0000 b24e6000 r-xp /usr/lib/osp/libosp-media.so.1.2.2.0
b24f9000 b25be000 r-xp /usr/lib/osp/libosp-net.so.1.2.2.0
b25cc000 b25e9000 r-xp /usr/lib/osp/libosp-image.so.1.2.2.0
b25f2000 b25f5000 r-xp /usr/lib/bufmgr/libtbm_exynos4412.so.0.0.0
b2604000 b266d000 r-xp /opt/usr/apps/X4TuAhqX38/bin/TizenProject.exe
b267a000 b26ec000 r-xp /usr/lib/libosp-env-config.so.1.2.2.1
b26f4000 b272e000 r-xp /usr/lib/libpulsecommon-0.9.23.so
b2737000 b273b000 r-xp /usr/lib/libmmfsoundcommon.so.0.0.0
b2743000 b2774000 r-xp /usr/lib/libpulse.so.0.12.4
b277c000 b27df000 r-xp /usr/lib/libasound.so.2.0.0
b27e9000 b27ec000 r-xp /usr/lib/libpulse-simple.so.0.0.3
b27f4000 b27f8000 r-xp /usr/lib/libascenario-0.2.so.0.0.0
b2801000 b281e000 r-xp /usr/lib/libavsysaudio.so.0.0.1
b2826000 b2834000 r-xp /usr/lib/libmmfsound.so.0.1.0
b283c000 b28d8000 r-xp /usr/lib/libgstreamer-0.10.so.0.30.0
b28e4000 b2925000 r-xp /usr/lib/libgstbase-0.10.so.0.30.0
b292e000 b2937000 r-xp /usr/lib/libgstapp-0.10.so.0.25.0
b293f000 b294c000 r-xp /usr/lib/libgstinterfaces-0.10.so.0.25.0
b2955000 b295b000 r-xp /usr/lib/libUMP.so
b2963000 b2966000 r-xp /usr/lib/libmm_ta.so.0.0.0
b296e000 b297d000 r-xp /usr/lib/libICE.so.6.3.0
b2987000 b298c000 r-xp /usr/lib/libSM.so.6.0.1
b2994000 b2995000 r-xp /usr/lib/libmmfkeysound.so.0.0.0
b299d000 b29a5000 r-xp /usr/lib/libmmfcommon.so.0.0.0
b29ad000 b29b5000 r-xp /usr/lib/libaudio-session-mgr.so.0.0.0
b29c0000 b29c3000 r-xp /usr/lib/libmmfsession.so.0.0.0
b29cb000 b2a0f000 r-xp /usr/lib/libmmfplayer.so.0.0.0
b2a18000 b2a2b000 r-xp /usr/lib/libEGL_platform.so
b2a34000 b2b0b000 r-xp /usr/lib/libMali.so
b2b16000 b2b1c000 r-xp /usr/lib/libxcb-render.so.0.0.0
b2b24000 b2b25000 r-xp /usr/lib/libxcb-shm.so.0.0.0
b2b2e000 b2b6c000 r-xp /usr/lib/libGLESv2.so.2.0
b2b74000 b2bbf000 r-xp /usr/lib/libtiff.so.5.1.0
b2bca000 b2bf3000 r-xp /usr/lib/libturbojpeg.so
b2c0c000 b2c12000 r-xp /usr/lib/libmmutil_imgp.so.0.0.0
b2c1a000 b2c20000 r-xp /usr/lib/libgif.so.4.1.6
b2c28000 b2c4a000 r-xp /usr/lib/libavutil.so.51.73.101
b2c59000 b2c87000 r-xp /usr/lib/libswscale.so.2.1.101
b2c90000 b2f87000 r-xp /usr/lib/libavcodec.so.54.59.100
b32ae000 b32c7000 r-xp /usr/lib/libpng12.so.0.50.0
b32d0000 b32d6000 r-xp /usr/lib/libfeedback.so.0.1.4
b32de000 b32ea000 r-xp /usr/lib/libtts.so
b32f2000 b3309000 r-xp /usr/lib/libEGL.so.1.4
b3312000 b33c9000 r-xp /usr/lib/libcairo.so.2.11200.12
b33d3000 b33ed000 r-xp /usr/lib/osp/libosp-image-core.so.1.2.2.0
b33f6000 b3cf1000 r-xp /usr/lib/osp/libosp-uifw.so.1.2.2.1
b3d64000 b3d69000 r-xp /usr/lib/libslp_devman_plugin.so
b3d72000 b3d75000 r-xp /usr/lib/libsyspopup_caller.so.0.1.0
b3d7d000 b3d81000 r-xp /usr/lib/libsysman.so.0.2.0
b3d89000 b3d9a000 r-xp /usr/lib/libsecurity-server-commons.so.1.0.0
b3da3000 b3da5000 r-xp /usr/lib/libsystemd-daemon.so.0.0.1
b3dad000 b3daf000 r-xp /usr/lib/libdeviced.so.0.1.0
b3db7000 b3dcd000 r-xp /usr/lib/libpkgmgr_parser.so.0.1.0
b3dd5000 b3dd7000 r-xp /usr/lib/libpkgmgr_installer_status_broadcast_server.so.0.1.0
b3ddf000 b3de2000 r-xp /usr/lib/libpkgmgr_installer_client.so.0.1.0
b3dea000 b3ded000 r-xp /usr/lib/libdevice-node.so.0.1
b3df5000 b3df9000 r-xp /usr/lib/libheynoti.so.0.0.2
b3e01000 b3e46000 r-xp /usr/lib/libsoup-2.4.so.1.5.0
b3e4f000 b3e64000 r-xp /usr/lib/libsecurity-server-client.so.1.0.1
b3e6d000 b3e71000 r-xp /usr/lib/libcapi-system-info.so.0.2.0
b3e79000 b3e7e000 r-xp /usr/lib/libcapi-system-system-settings.so.0.0.2
b3e86000 b3e87000 r-xp /usr/lib/libcapi-system-power.so.0.1.1
b3e90000 b3e93000 r-xp /usr/lib/libcapi-system-device.so.0.1.0
b3e9b000 b3e9e000 r-xp /usr/lib/libcapi-system-runtime-info.so.0.0.3
b3ea7000 b3eaa000 r-xp /usr/lib/libcapi-network-serial.so.0.0.8
b3eb2000 b3eb3000 r-xp /usr/lib/libcapi-content-mime-type.so.0.0.2
b3ebb000 b3ec9000 r-xp /usr/lib/libcapi-appfw-application.so.0.1.0
b3ed2000 b3ef4000 r-xp /usr/lib/libSLP-tapi.so.0.0.0
b3efc000 b3eff000 r-xp /usr/lib/libuuid.so.1.3.0
b3f08000 b3f26000 r-xp /usr/lib/libpkgmgr-info.so.0.0.17
b3f2e000 b3f45000 r-xp /usr/lib/libpkgmgr-client.so.0.1.68
b3f4e000 b3f4f000 r-xp /usr/lib/libpmapi.so.1.2
b3f57000 b3f5f000 r-xp /usr/lib/libminizip.so.1.0.0
b3f67000 b3f72000 r-xp /usr/lib/libmessage-port.so.1.2.2.1
b3f7a000 b4052000 r-xp /usr/lib/libxml2.so.2.7.8
b405f000 b407d000 r-xp /usr/lib/libpcre.so.0.0.1
b4085000 b4088000 r-xp /usr/lib/libiniparser.so.0
b4091000 b4095000 r-xp /usr/lib/libhaptic.so.0.1
b409d000 b40a8000 r-xp /usr/lib/libcryptsvc.so.0.0.1
b40b5000 b40ba000 r-xp /usr/lib/libdevman.so.0.1
b40c3000 b40c7000 r-xp /usr/lib/libchromium.so.1.0
b40cf000 b40d5000 r-xp /usr/lib/libappsvc.so.0.1.0
b40dd000 b40de000 r-xp /usr/lib/osp/libappinfo.so.1.2.2.1
b40ee000 b40f0000 r-xp /opt/usr/apps/X4TuAhqX38/bin/TizenProject
b40f8000 b40fe000 r-xp /usr/lib/libalarm.so.0.0.0
b4107000 b4119000 r-xp /usr/lib/libprivacy-manager-client.so.0.0.5
b4121000 b4420000 r-xp /usr/lib/osp/libosp-appfw.so.1.2.2.1
b4447000 b4451000 r-xp /lib/libnss_files-2.13.so
b445a000 b4463000 r-xp /lib/libnss_nis-2.13.so
b446c000 b447d000 r-xp /lib/libnsl-2.13.so
b4488000 b448e000 r-xp /lib/libnss_compat-2.13.so
b4497000 b44a0000 r-xp /usr/lib/libcapi-security-privilege-manager.so.0.0.3
b47c8000 b47d9000 r-xp /usr/lib/libcom-core.so.0.0.1
b47e1000 b47e3000 r-xp /usr/lib/libdri2.so.0.0.0
b47eb000 b47f3000 r-xp /usr/lib/libdrm.so.2.4.0
b47fb000 b47ff000 r-xp /usr/lib/libtbm.so.1.0.0
b4807000 b480a000 r-xp /usr/lib/libXv.so.1.0.0
b4812000 b48dd000 r-xp /usr/lib/libscim-1.0.so.8.2.3
b48f3000 b4903000 r-xp /usr/lib/libnotification.so.0.1.0
b490b000 b492f000 r-xp /usr/lib/ecore/immodules/libisf-imf-module.so
b4938000 b4948000 r-xp /lib/libresolv-2.13.so
b494c000 b494e000 r-xp /usr/lib/libgmodule-2.0.so.0.3200.3
b4956000 b4aa9000 r-xp /usr/lib/libcrypto.so.1.0.0
b4ac7000 b4b13000 r-xp /usr/lib/libssl.so.1.0.0
b4b1f000 b4b4b000 r-xp /usr/lib/libidn.so.11.5.44
b4b54000 b4b5e000 r-xp /usr/lib/libcares.so.2.0.0
b4b66000 b4b7d000 r-xp /lib/libexpat.so.1.5.2
b4b87000 b4bab000 r-xp /usr/lib/libicule.so.48.1
b4bb4000 b4bbc000 r-xp /usr/lib/libsf_common.so
b4bc4000 b4c5f000 r-xp /usr/lib/libstdc++.so.6.0.14
b4c72000 b4d4f000 r-xp /usr/lib/libgio-2.0.so.0.3200.3
b4d5a000 b4d7f000 r-xp /usr/lib/libexif.so.12.3.3
b4d93000 b4d9d000 r-xp /usr/lib/libethumb.so.1.7.99
b4da5000 b4de9000 r-xp /usr/lib/libsndfile.so.1.0.25
b4df7000 b4df9000 r-xp /usr/lib/libctxdata.so.0.0.0
b4e01000 b4e0f000 r-xp /usr/lib/libremix.so.0.0.0
b4e17000 b4e18000 r-xp /usr/lib/libecore_imf_evas.so.1.7.99
b4e20000 b4e39000 r-xp /usr/lib/liblua-5.1.so
b4e42000 b4e49000 r-xp /usr/lib/libembryo.so.1.7.99
b4e52000 b4e55000 r-xp /usr/lib/libecore_input_evas.so.1.7.99
b4e5d000 b4e9a000 r-xp /usr/lib/libcurl.so.4.3.0
b4ea4000 b4ea8000 r-xp /usr/lib/libecore_ipc.so.1.7.99
b4eb1000 b4f1b000 r-xp /usr/lib/libpixman-1.so.0.28.2
b4f28000 b4f4c000 r-xp /usr/lib/libfontconfig.so.1.5.0
b4f55000 b4fb1000 r-xp /usr/lib/libharfbuzz.so.0.907.0
b4fc3000 b4fd7000 r-xp /usr/lib/libfribidi.so.0.3.1
b4fdf000 b5034000 r-xp /usr/lib/libfreetype.so.6.8.1
b503f000 b5063000 r-xp /usr/lib/libjpeg.so.8.0.2
b507b000 b5092000 r-xp /lib/libz.so.1.2.5
b509a000 b50a7000 r-xp /usr/lib/libsensor.so.1.1.0
b50b2000 b50b4000 r-xp /usr/lib/libapp-checker.so.0.1.0
b50bc000 b50c2000 r-xp /usr/lib/libxdgmime.so.1.1.0
b61d9000 b62c1000 r-xp /usr/lib/libicuuc.so.48.1
b62ce000 b63ee000 r-xp /usr/lib/libicui18n.so.48.1
b63fc000 b63ff000 r-xp /usr/lib/libSLP-db-util.so.0.1.0
b6407000 b6410000 r-xp /usr/lib/libvconf.so.0.2.45
b6418000 b6426000 r-xp /usr/lib/libail.so.0.1.0
b642e000 b6446000 r-xp /usr/lib/libdbus-glib-1.so.2.2.2
b6447000 b644c000 r-xp /usr/lib/libffi.so.5.0.10
b6454000 b6455000 r-xp /usr/lib/libgthread-2.0.so.0.3200.3
b645d000 b6467000 r-xp /usr/lib/libXext.so.6.4.0
b6470000 b6473000 r-xp /usr/lib/libXtst.so.6.1.0
b647b000 b6481000 r-xp /usr/lib/libXrender.so.1.3.0
b6489000 b648f000 r-xp /usr/lib/libXrandr.so.2.2.0
b6497000 b6498000 r-xp /usr/lib/libXinerama.so.1.0.0
b64a1000 b64aa000 r-xp /usr/lib/libXi.so.6.1.0
b64b2000 b64b5000 r-xp /usr/lib/libXfixes.so.3.1.0
b64bd000 b64bf000 r-xp /usr/lib/libXgesture.so.7.0.0
b64c7000 b64c9000 r-xp /usr/lib/libXcomposite.so.1.0.0
b64d1000 b64d2000 r-xp /usr/lib/libXdamage.so.1.1.0
b64db000 b64e2000 r-xp /usr/lib/libXcursor.so.1.0.2
b64ea000 b64f2000 r-xp /usr/lib/libemotion.so.1.7.99
b64fa000 b6515000 r-xp /usr/lib/libecore_con.so.1.7.99
b651e000 b6523000 r-xp /usr/lib/libecore_imf.so.1.7.99
b652c000 b6534000 r-xp /usr/lib/libethumb_client.so.1.7.99
b653c000 b653e000 r-xp /usr/lib/libefreet_trash.so.1.7.99
b6546000 b654a000 r-xp /usr/lib/libefreet_mime.so.1.7.99
b6553000 b6569000 r-xp /usr/lib/libefreet.so.1.7.99
b6573000 b657c000 r-xp /usr/lib/libedbus.so.1.7.99
b6584000 b6589000 r-xp /usr/lib/libecore_fb.so.1.7.99
b6592000 b65ee000 r-xp /usr/lib/libedje.so.1.7.99
b65f8000 b660f000 r-xp /usr/lib/libecore_input.so.1.7.99
b662a000 b662f000 r-xp /usr/lib/libecore_file.so.1.7.99
b6637000 b6654000 r-xp /usr/lib/libecore_evas.so.1.7.99
b665d000 b669c000 r-xp /usr/lib/libeina.so.1.7.99
b66a5000 b6754000 r-xp /usr/lib/libevas.so.1.7.99
b6776000 b6789000 r-xp /usr/lib/libeet.so.1.7.99
b6792000 b67fc000 r-xp /lib/libm-2.13.so
b6808000 b680f000 r-xp /usr/lib/libutilX.so.1.1.0
b6817000 b681c000 r-xp /usr/lib/libappcore-common.so.1.1
b6824000 b682f000 r-xp /usr/lib/libaul.so.0.1.0
b6838000 b686c000 r-xp /usr/lib/libgobject-2.0.so.0.3200.3
b6875000 b68a5000 r-xp /usr/lib/libecore_x.so.1.7.99
b68ae000 b68c3000 r-xp /usr/lib/libecore.so.1.7.99
b68da000 b69fa000 r-xp /usr/lib/libelementary.so.1.7.99
b6a0d000 b6a10000 r-xp /lib/libattr.so.1.1.0
b6a18000 b6a1a000 r-xp /usr/lib/libXau.so.6.0.0
b6a22000 b6a28000 r-xp /lib/librt-2.13.so
b6a31000 b6a39000 r-xp /lib/libcrypt-2.13.so
b6a69000 b6a6c000 r-xp /lib/libcap.so.2.21
b6a74000 b6a76000 r-xp /usr/lib/libiri.so
b6a7e000 b6a93000 r-xp /usr/lib/libxcb.so.1.1.0
b6a9b000 b6aa6000 r-xp /lib/libunwind.so.8.0.1
b6ad4000 b6bf1000 r-xp /lib/libc-2.13.so
b6bff000 b6c08000 r-xp /lib/libgcc_s-4.5.3.so.1
b6c10000 b6c13000 r-xp /usr/lib/libsmack.so.1.0.0
b6c1b000 b6c47000 r-xp /usr/lib/libdbus-1.so.3.7.2
b6c50000 b6c54000 r-xp /usr/lib/libbundle.so.0.1.22
b6c5c000 b6c5e000 r-xp /lib/libdl-2.13.so
b6c67000 b6d41000 r-xp /usr/lib/libglib-2.0.so.0.3200.3
b6d4a000 b6db4000 r-xp /usr/lib/libsqlite3.so.0.8.6
b6dbe000 b6dcb000 r-xp /usr/lib/libprivilege-control.so.0.0.2
b6dd4000 b6eba000 r-xp /usr/lib/libX11.so.6.3.0
b6ec5000 b6ed9000 r-xp /lib/libpthread-2.13.so
b6ee9000 b6eed000 r-xp /usr/lib/libappcore-efl.so.1.1
b6ef6000 b6ef7000 r-xp /usr/lib/libdlog.so.0.0.0
b6eff000 b6f03000 r-xp /usr/lib/libsys-assert.so
b6f0b000 b6f28000 r-xp /lib/ld-2.13.so
bee9e000 beebf000 rwxp [stack]
End of Maps Information

Callstack Information (PID:19377)
Call Stack Count: 32
 0: Tizen::Graphics::Rectangle::Rectangle(Tizen::Graphics::Rectangle const&) + 0xf (0xb3a2249c) [/usr/lib/osp/libosp-uifw.so] + 0x62c49c
 1: JMChattControl::GetImageIndexByPoint(Tizen::Graphics::Point) + 0xa8 (0xb263dccc) [/opt/apps/X4TuAhqX38/bin/TizenProject.exe] + 0x39ccc
 2: JMChattControl::OnTouchPressed(Tizen::Ui::Control const&, Tizen::Graphics::Point const&, Tizen::Ui::TouchEventInfo const&) + 0xfc (0xb263dbb4) [/opt/apps/X4TuAhqX38/bin/TizenProject.exe] + 0x39bb4
 3: non-virtual thunk to JMChattControl::OnTouchPressed(Tizen::Ui::Control const&, Tizen::Graphics::Point const&, Tizen::Ui::TouchEventInfo const&) + 0x4c (0xb263de48) [/opt/apps/X4TuAhqX38/bin/TizenProject.exe] + 0x39e48
 4: Tizen::Ui::_ControlImpl::CoreTouchEvent::ProcessListener(Tizen::Ui::_TouchInfo const&) + 0x224 (0xb36c37fd) [/usr/lib/osp/libosp-uifw.so] + 0x2cd7fd
 5: Tizen::Ui::_ControlImpl::CallOnTouchPressed(Tizen::Ui::_Control const&, Tizen::Ui::_TouchInfo const&) + 0xac (0xb36bc8dd) [/usr/lib/osp/libosp-uifw.so] + 0x2c68dd
 6: Tizen::Ui::_ControlImpl::_PropagatedTouchEventListener::OnTouchPressed(Tizen::Ui::_Control const&, Tizen::Ui::_TouchInfo const&) + 0x200 (0xb36c4279) [/usr/lib/osp/libosp-uifw.so] + 0x2ce279
 7: Tizen::Ui::_UiTouchEvent::FireListener(Tizen::Ui::_ITouchEventListener const*, Tizen::Ui::_Control const*, bool, bool&) + 0x2de (0xb372a96b) [/usr/lib/osp/libosp-uifw.so] + 0x33496b
 8: Tizen::Ui::_UiTouchEvent::OnEventProcessing(Tizen::Ui::_Control const&, bool&) + 0x62 (0xb372ae43) [/usr/lib/osp/libosp-uifw.so] + 0x334e43
 9: Tizen::Ui::_UiEvent::ProcessEvent(Tizen::Ui::_Control const&, bool&) + 0x32 (0xb371ef53) [/usr/lib/osp/libosp-uifw.so] + 0x328f53
10: Tizen::Ui::_UiEventManager::ProcessBubblingEvent(Tizen::Base::Collection::LinkedListT<Tizen::Base::_HandleT<Tizen::Ui::_Control> > const&, Tizen::Ui::_UiEvent const&, bool&) + 0x78 (0xb371f901) [/usr/lib/osp/libosp-uifw.so] + 0x329901
11: Tizen::Ui::_UiEventManager::ProcessEvent(Tizen::Ui::_UiEvent const&, bool&) + 0x234 (0xb371fbd5) [/usr/lib/osp/libosp-uifw.so] + 0x329bd5
12: Tizen::Ui::_UiEventManager::Fire(Tizen::Ui::_UiEvent const&) + 0x8c (0xb371fcb9) [/usr/lib/osp/libosp-uifw.so] + 0x329cb9
13: Tizen::Ui::_UiEventManager::SendEvent(Tizen::Ui::_UiEvent const&) + 0x6 (0xb371fd4b) [/usr/lib/osp/libosp-uifw.so] + 0x329d4b
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
