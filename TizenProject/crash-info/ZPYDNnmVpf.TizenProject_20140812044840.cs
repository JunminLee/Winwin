S/W Version Information
Model: Ref.Device-PQ
Tizen-Version: 2.2.1
Build-Number: Tizen_Ref.Device-PQ_20131118.1124
Build-Date: 2013.11.18 11:24:59

Crash Information
Process Name: TizenProject
PID: 22855
Date: 2014-08-12 04:48:40(GMT+0900)
Executable File Path: /opt/apps/ZPYDNnmVpf/bin/TizenProject
This process is multi-thread process
pid=22855 tid=22855
Signal: 11
      (SIGSEGV)
      si_code: -6
      signal sent by tkill (sent by pid 22855, uid 5000)

Register Information
r0   = 0x0032ce68, r1   = 0x00000000
r2   = 0x00000005, r3   = 0x00000025
r4   = 0xfffedfc6, r5   = 0x007f5c30
r6   = 0x00be0db0, r7   = 0xbedb6608
r8   = 0x00be00a8, r9   = 0x00be0de8
r10  = 0xbedb640c, fp   = 0xbedb63b8
ip   = 0xb69f3b98, sp   = 0xbedb5f70
lr   = 0xb423756b, pc   = 0xb262a7cc
cpsr = 0x08000010

Memory Information
MemTotal:   797320 KB
MemFree:     13576 KB
Buffers:      3720 KB
Cached:     289652 KB
VmPeak:     274448 KB
VmSize:     193656 KB
VmLck:           0 KB
VmHWM:      105536 KB
VmRSS:      105536 KB
VmData:     118164 KB
VmStk:         136 KB
VmExe:          32 KB
VmLib:       44288 KB
VmPTE:         250 KB
VmSwap:          0 KB

Maps Information
00008000 00010000 r-xp /usr/bin/launchpad_preloading_preinitializing_daemon
00018000 000dc000 rw-p [heap]
000dc000 00e9a000 rw-p [heap]
a89a8000 a89aa000 r-xp /usr/lib/evas/modules/loaders/png/linux-gnueabi-armv7l-1.7.99/module.so
ab19c000 ab1a1000 r-xp /usr/lib/libhaptic-module.so
af34f000 af360000 r-xp /usr/lib/scim-1.0/1.4.0/IMEngine/socket.so
b0802000 b0807000 r-xp /usr/lib/scim-1.0/1.4.0/Config/socket.so
b0bc2000 b0bc5000 r-xp /usr/lib/bufmgr/libtbm_exynos4412.so.0.0.0
b240d000 b2458000 r-xp /usr/lib/libGLESv1_CM.so.1.1
b2461000 b2489000 r-xp /usr/lib/evas/modules/engines/gl_x11/linux-gnueabi-armv7l-1.7.99/module.so
b24b1000 b24c5000 r-xp /usr/lib/libnetwork.so.0.0.0
b24ce000 b24e2000 r-xp /usr/lib/libwifi-direct.so.0.0
b24ea000 b24f2000 r-xp /usr/lib/libcapi-network-tethering.so.0.1.0
b24f3000 b24fc000 r-xp /usr/lib/libcapi-network-connection.so.0.1.3_18
b2504000 b25c9000 r-xp /usr/lib/osp/libosp-net.so.1.2.2.0
b25d7000 b25f4000 r-xp /usr/lib/osp/libosp-image.so.1.2.2.0
b25fd000 b2607000 r-xp /usr/lib/evas/modules/engines/software_generic/linux-gnueabi-armv7l-1.7.99/module.so
b260f000 b2656000 r-xp /opt/usr/apps/ZPYDNnmVpf/bin/TizenProject.exe
b2661000 b26d3000 r-xp /usr/lib/libosp-env-config.so.1.2.2.1
b26db000 b2715000 r-xp /usr/lib/libpulsecommon-0.9.23.so
b271e000 b2722000 r-xp /usr/lib/libmmfsoundcommon.so.0.0.0
b272a000 b275b000 r-xp /usr/lib/libpulse.so.0.12.4
b2763000 b27c6000 r-xp /usr/lib/libasound.so.2.0.0
b27d0000 b27d3000 r-xp /usr/lib/libpulse-simple.so.0.0.3
b27db000 b27df000 r-xp /usr/lib/libascenario-0.2.so.0.0.0
b27e8000 b2805000 r-xp /usr/lib/libavsysaudio.so.0.0.1
b280d000 b281b000 r-xp /usr/lib/libmmfsound.so.0.1.0
b2823000 b28bf000 r-xp /usr/lib/libgstreamer-0.10.so.0.30.0
b28cb000 b290c000 r-xp /usr/lib/libgstbase-0.10.so.0.30.0
b2915000 b291e000 r-xp /usr/lib/libgstapp-0.10.so.0.25.0
b2926000 b2933000 r-xp /usr/lib/libgstinterfaces-0.10.so.0.25.0
b293c000 b2942000 r-xp /usr/lib/libUMP.so
b294a000 b294d000 r-xp /usr/lib/libmm_ta.so.0.0.0
b2955000 b2964000 r-xp /usr/lib/libICE.so.6.3.0
b296e000 b2973000 r-xp /usr/lib/libSM.so.6.0.1
b297b000 b297c000 r-xp /usr/lib/libmmfkeysound.so.0.0.0
b2984000 b298c000 r-xp /usr/lib/libmmfcommon.so.0.0.0
b2994000 b299c000 r-xp /usr/lib/libaudio-session-mgr.so.0.0.0
b29a7000 b29aa000 r-xp /usr/lib/libmmfsession.so.0.0.0
b29b2000 b29f6000 r-xp /usr/lib/libmmfplayer.so.0.0.0
b29ff000 b2a12000 r-xp /usr/lib/libEGL_platform.so
b2a1b000 b2af2000 r-xp /usr/lib/libMali.so
b2afd000 b2b03000 r-xp /usr/lib/libxcb-render.so.0.0.0
b2b0b000 b2b0c000 r-xp /usr/lib/libxcb-shm.so.0.0.0
b2b15000 b2b53000 r-xp /usr/lib/libGLESv2.so.2.0
b2b5b000 b2ba6000 r-xp /usr/lib/libtiff.so.5.1.0
b2bb1000 b2bda000 r-xp /usr/lib/libturbojpeg.so
b2bf3000 b2bf9000 r-xp /usr/lib/libmmutil_imgp.so.0.0.0
b2c01000 b2c07000 r-xp /usr/lib/libgif.so.4.1.6
b2c0f000 b2c31000 r-xp /usr/lib/libavutil.so.51.73.101
b2c40000 b2c6e000 r-xp /usr/lib/libswscale.so.2.1.101
b2c77000 b2f6e000 r-xp /usr/lib/libavcodec.so.54.59.100
b3295000 b32ae000 r-xp /usr/lib/libpng12.so.0.50.0
b32b7000 b32bd000 r-xp /usr/lib/libfeedback.so.0.1.4
b32c5000 b32d1000 r-xp /usr/lib/libtts.so
b32d9000 b32f0000 r-xp /usr/lib/libEGL.so.1.4
b32f9000 b33b0000 r-xp /usr/lib/libcairo.so.2.11200.12
b33ba000 b33d4000 r-xp /usr/lib/osp/libosp-image-core.so.1.2.2.0
b33dd000 b3cd8000 r-xp /usr/lib/osp/libosp-uifw.so.1.2.2.1
b3d4b000 b3d50000 r-xp /usr/lib/libslp_devman_plugin.so
b3d59000 b3d5c000 r-xp /usr/lib/libsyspopup_caller.so.0.1.0
b3d64000 b3d68000 r-xp /usr/lib/libsysman.so.0.2.0
b3d70000 b3d81000 r-xp /usr/lib/libsecurity-server-commons.so.1.0.0
b3d8a000 b3d8c000 r-xp /usr/lib/libsystemd-daemon.so.0.0.1
b3d94000 b3d96000 r-xp /usr/lib/libdeviced.so.0.1.0
b3d9e000 b3db4000 r-xp /usr/lib/libpkgmgr_parser.so.0.1.0
b3dbc000 b3dbe000 r-xp /usr/lib/libpkgmgr_installer_status_broadcast_server.so.0.1.0
b3dc6000 b3dc9000 r-xp /usr/lib/libpkgmgr_installer_client.so.0.1.0
b3dd1000 b3dd4000 r-xp /usr/lib/libdevice-node.so.0.1
b3ddc000 b3de0000 r-xp /usr/lib/libheynoti.so.0.0.2
b3de8000 b3e2d000 r-xp /usr/lib/libsoup-2.4.so.1.5.0
b3e36000 b3e4b000 r-xp /usr/lib/libsecurity-server-client.so.1.0.1
b3e54000 b3e58000 r-xp /usr/lib/libcapi-system-info.so.0.2.0
b3e60000 b3e65000 r-xp /usr/lib/libcapi-system-system-settings.so.0.0.2
b3e6d000 b3e6e000 r-xp /usr/lib/libcapi-system-power.so.0.1.1
b3e77000 b3e7a000 r-xp /usr/lib/libcapi-system-device.so.0.1.0
b3e82000 b3e85000 r-xp /usr/lib/libcapi-system-runtime-info.so.0.0.3
b3e8e000 b3e91000 r-xp /usr/lib/libcapi-network-serial.so.0.0.8
b3e99000 b3e9a000 r-xp /usr/lib/libcapi-content-mime-type.so.0.0.2
b3ea2000 b3eb0000 r-xp /usr/lib/libcapi-appfw-application.so.0.1.0
b3eb9000 b3edb000 r-xp /usr/lib/libSLP-tapi.so.0.0.0
b3ee3000 b3ee6000 r-xp /usr/lib/libuuid.so.1.3.0
b3eef000 b3f0d000 r-xp /usr/lib/libpkgmgr-info.so.0.0.17
b3f15000 b3f2c000 r-xp /usr/lib/libpkgmgr-client.so.0.1.68
b3f35000 b3f36000 r-xp /usr/lib/libpmapi.so.1.2
b3f3e000 b3f46000 r-xp /usr/lib/libminizip.so.1.0.0
b3f4e000 b3f59000 r-xp /usr/lib/libmessage-port.so.1.2.2.1
b3f61000 b4039000 r-xp /usr/lib/libxml2.so.2.7.8
b4046000 b4064000 r-xp /usr/lib/libpcre.so.0.0.1
b406c000 b406f000 r-xp /usr/lib/libiniparser.so.0
b4078000 b407c000 r-xp /usr/lib/libhaptic.so.0.1
b4084000 b408f000 r-xp /usr/lib/libcryptsvc.so.0.0.1
b409c000 b40a1000 r-xp /usr/lib/libdevman.so.0.1
b40aa000 b40ae000 r-xp /usr/lib/libchromium.so.1.0
b40b6000 b40bc000 r-xp /usr/lib/libappsvc.so.0.1.0
b40c4000 b40c5000 r-xp /usr/lib/osp/libappinfo.so.1.2.2.1
b40d5000 b40d7000 r-xp /opt/usr/apps/ZPYDNnmVpf/bin/TizenProject
b40df000 b40e5000 r-xp /usr/lib/libalarm.so.0.0.0
b40ee000 b4100000 r-xp /usr/lib/libprivacy-manager-client.so.0.0.5
b4108000 b4407000 r-xp /usr/lib/osp/libosp-appfw.so.1.2.2.1
b442e000 b4438000 r-xp /lib/libnss_files-2.13.so
b4441000 b444a000 r-xp /lib/libnss_nis-2.13.so
b4453000 b4464000 r-xp /lib/libnsl-2.13.so
b446f000 b4475000 r-xp /lib/libnss_compat-2.13.so
b447e000 b4487000 r-xp /usr/lib/libcapi-security-privilege-manager.so.0.0.3
b47af000 b47c0000 r-xp /usr/lib/libcom-core.so.0.0.1
b47c8000 b47ca000 r-xp /usr/lib/libdri2.so.0.0.0
b47d2000 b47da000 r-xp /usr/lib/libdrm.so.2.4.0
b47e2000 b47e6000 r-xp /usr/lib/libtbm.so.1.0.0
b47ee000 b47f1000 r-xp /usr/lib/libXv.so.1.0.0
b47f9000 b48c4000 r-xp /usr/lib/libscim-1.0.so.8.2.3
b48da000 b48ea000 r-xp /usr/lib/libnotification.so.0.1.0
b48f2000 b4916000 r-xp /usr/lib/ecore/immodules/libisf-imf-module.so
b491f000 b492f000 r-xp /lib/libresolv-2.13.so
b4933000 b4935000 r-xp /usr/lib/libgmodule-2.0.so.0.3200.3
b493d000 b4a90000 r-xp /usr/lib/libcrypto.so.1.0.0
b4aae000 b4afa000 r-xp /usr/lib/libssl.so.1.0.0
b4b06000 b4b32000 r-xp /usr/lib/libidn.so.11.5.44
b4b3b000 b4b45000 r-xp /usr/lib/libcares.so.2.0.0
b4b4d000 b4b64000 r-xp /lib/libexpat.so.1.5.2
b4b6e000 b4b92000 r-xp /usr/lib/libicule.so.48.1
b4b9b000 b4ba3000 r-xp /usr/lib/libsf_common.so
b4bab000 b4c46000 r-xp /usr/lib/libstdc++.so.6.0.14
b4c59000 b4d36000 r-xp /usr/lib/libgio-2.0.so.0.3200.3
b4d41000 b4d66000 r-xp /usr/lib/libexif.so.12.3.3
b4d7a000 b4d84000 r-xp /usr/lib/libethumb.so.1.7.99
b4d8c000 b4dd0000 r-xp /usr/lib/libsndfile.so.1.0.25
b4dde000 b4de0000 r-xp /usr/lib/libctxdata.so.0.0.0
b4de8000 b4df6000 r-xp /usr/lib/libremix.so.0.0.0
b4dfe000 b4dff000 r-xp /usr/lib/libecore_imf_evas.so.1.7.99
b4e07000 b4e20000 r-xp /usr/lib/liblua-5.1.so
b4e29000 b4e30000 r-xp /usr/lib/libembryo.so.1.7.99
b4e39000 b4e3c000 r-xp /usr/lib/libecore_input_evas.so.1.7.99
b4e44000 b4e81000 r-xp /usr/lib/libcurl.so.4.3.0
b4e8b000 b4e8f000 r-xp /usr/lib/libecore_ipc.so.1.7.99
b4e98000 b4f02000 r-xp /usr/lib/libpixman-1.so.0.28.2
b4f0f000 b4f33000 r-xp /usr/lib/libfontconfig.so.1.5.0
b4f3c000 b4f98000 r-xp /usr/lib/libharfbuzz.so.0.907.0
b4faa000 b4fbe000 r-xp /usr/lib/libfribidi.so.0.3.1
b4fc6000 b501b000 r-xp /usr/lib/libfreetype.so.6.8.1
b5026000 b504a000 r-xp /usr/lib/libjpeg.so.8.0.2
b5062000 b5079000 r-xp /lib/libz.so.1.2.5
b5081000 b508e000 r-xp /usr/lib/libsensor.so.1.1.0
b5099000 b509b000 r-xp /usr/lib/libapp-checker.so.0.1.0
b50a3000 b50a9000 r-xp /usr/lib/libxdgmime.so.1.1.0
b61c0000 b62a8000 r-xp /usr/lib/libicuuc.so.48.1
b62b5000 b63d5000 r-xp /usr/lib/libicui18n.so.48.1
b63e3000 b63e6000 r-xp /usr/lib/libSLP-db-util.so.0.1.0
b63ee000 b63f7000 r-xp /usr/lib/libvconf.so.0.2.45
b63ff000 b640d000 r-xp /usr/lib/libail.so.0.1.0
b6415000 b642d000 r-xp /usr/lib/libdbus-glib-1.so.2.2.2
b642e000 b6433000 r-xp /usr/lib/libffi.so.5.0.10
b643b000 b643c000 r-xp /usr/lib/libgthread-2.0.so.0.3200.3
b6444000 b644e000 r-xp /usr/lib/libXext.so.6.4.0
b6457000 b645a000 r-xp /usr/lib/libXtst.so.6.1.0
b6462000 b6468000 r-xp /usr/lib/libXrender.so.1.3.0
b6470000 b6476000 r-xp /usr/lib/libXrandr.so.2.2.0
b647e000 b647f000 r-xp /usr/lib/libXinerama.so.1.0.0
b6488000 b6491000 r-xp /usr/lib/libXi.so.6.1.0
b6499000 b649c000 r-xp /usr/lib/libXfixes.so.3.1.0
b64a4000 b64a6000 r-xp /usr/lib/libXgesture.so.7.0.0
b64ae000 b64b0000 r-xp /usr/lib/libXcomposite.so.1.0.0
b64b8000 b64b9000 r-xp /usr/lib/libXdamage.so.1.1.0
b64c2000 b64c9000 r-xp /usr/lib/libXcursor.so.1.0.2
b64d1000 b64d9000 r-xp /usr/lib/libemotion.so.1.7.99
b64e1000 b64fc000 r-xp /usr/lib/libecore_con.so.1.7.99
b6505000 b650a000 r-xp /usr/lib/libecore_imf.so.1.7.99
b6513000 b651b000 r-xp /usr/lib/libethumb_client.so.1.7.99
b6523000 b6525000 r-xp /usr/lib/libefreet_trash.so.1.7.99
b652d000 b6531000 r-xp /usr/lib/libefreet_mime.so.1.7.99
b653a000 b6550000 r-xp /usr/lib/libefreet.so.1.7.99
b655a000 b6563000 r-xp /usr/lib/libedbus.so.1.7.99
b656b000 b6570000 r-xp /usr/lib/libecore_fb.so.1.7.99
b6579000 b65d5000 r-xp /usr/lib/libedje.so.1.7.99
b65df000 b65f6000 r-xp /usr/lib/libecore_input.so.1.7.99
b6611000 b6616000 r-xp /usr/lib/libecore_file.so.1.7.99
b661e000 b663b000 r-xp /usr/lib/libecore_evas.so.1.7.99
b6644000 b6683000 r-xp /usr/lib/libeina.so.1.7.99
b668c000 b673b000 r-xp /usr/lib/libevas.so.1.7.99
b675d000 b6770000 r-xp /usr/lib/libeet.so.1.7.99
b6779000 b67e3000 r-xp /lib/libm-2.13.so
b67ef000 b67f6000 r-xp /usr/lib/libutilX.so.1.1.0
b67fe000 b6803000 r-xp /usr/lib/libappcore-common.so.1.1
b680b000 b6816000 r-xp /usr/lib/libaul.so.0.1.0
b681f000 b6853000 r-xp /usr/lib/libgobject-2.0.so.0.3200.3
b685c000 b688c000 r-xp /usr/lib/libecore_x.so.1.7.99
b6895000 b68aa000 r-xp /usr/lib/libecore.so.1.7.99
b68c1000 b69e1000 r-xp /usr/lib/libelementary.so.1.7.99
b69f4000 b69f7000 r-xp /lib/libattr.so.1.1.0
b69ff000 b6a01000 r-xp /usr/lib/libXau.so.6.0.0
b6a09000 b6a0f000 r-xp /lib/librt-2.13.so
b6a18000 b6a20000 r-xp /lib/libcrypt-2.13.so
b6a50000 b6a53000 r-xp /lib/libcap.so.2.21
b6a5b000 b6a5d000 r-xp /usr/lib/libiri.so
b6a65000 b6a7a000 r-xp /usr/lib/libxcb.so.1.1.0
b6a82000 b6a8d000 r-xp /lib/libunwind.so.8.0.1
b6abb000 b6bd8000 r-xp /lib/libc-2.13.so
b6be6000 b6bef000 r-xp /lib/libgcc_s-4.5.3.so.1
b6bf7000 b6bfa000 r-xp /usr/lib/libsmack.so.1.0.0
b6c02000 b6c2e000 r-xp /usr/lib/libdbus-1.so.3.7.2
b6c37000 b6c3b000 r-xp /usr/lib/libbundle.so.0.1.22
b6c43000 b6c45000 r-xp /lib/libdl-2.13.so
b6c4e000 b6d28000 r-xp /usr/lib/libglib-2.0.so.0.3200.3
b6d31000 b6d9b000 r-xp /usr/lib/libsqlite3.so.0.8.6
b6da5000 b6db2000 r-xp /usr/lib/libprivilege-control.so.0.0.2
b6dbb000 b6ea1000 r-xp /usr/lib/libX11.so.6.3.0
b6eac000 b6ec0000 r-xp /lib/libpthread-2.13.so
b6ed0000 b6ed4000 r-xp /usr/lib/libappcore-efl.so.1.1
b6edd000 b6ede000 r-xp /usr/lib/libdlog.so.0.0.0
b6ee6000 b6eea000 r-xp /usr/lib/libsys-assert.so
b6ef2000 b6f0f000 r-xp /lib/ld-2.13.so
bed97000 bedb8000 rwxp [stack]
End of Maps Information

Callstack Information (PID:22855)
Call Stack Count: 26
 0: Editing::OnKeyReleased(Tizen::Ui::Control const&, Tizen::Ui::KeyCode) + 0x15ac (0xb262a7cc) [/opt/apps/ZPYDNnmVpf/bin/TizenProject.exe] + 0x1b7cc
 1: non-virtual thunk to Editing::OnKeyReleased(Tizen::Ui::Control const&, Tizen::Ui::KeyCode) + 0x3c (0xb262b210) [/opt/apps/ZPYDNnmVpf/bin/TizenProject.exe] + 0x1c210
 2: Tizen::Ui::_ControlImpl::_PropagatedKeyEventListener::OnKeyReleased(Tizen::Ui::_Control const&, Tizen::Ui::_KeyInfo const&) + 0x150 (0xb36ac295) [/usr/lib/osp/libosp-uifw.so] + 0x2cf295
End of Call Stack

Package Information
Package Name: ZPYDNnmVpf.TizenProject
Package ID : ZPYDNnmVpf
Version: 1.0.0
Package Type: tpk
App Name: TizenProject
App ID: ZPYDNnmVpf.TizenProject
Type: Application
Categories: (NULL)
