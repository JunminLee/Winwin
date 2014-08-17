S/W Version Information
Model: Ref.Device-PQ
Tizen-Version: 2.2.1
Build-Number: Tizen_Ref.Device-PQ_20131118.1124
Build-Date: 2013.11.18 11:24:59

Crash Information
Process Name: TizenProject
PID: 4268
Date: 2014-08-17 15:08:01(GMT+0900)
Executable File Path: /opt/apps/ZPYDNnmVpf/bin/TizenProject
This process is multi-thread process
pid=4268 tid=4268
Signal: 11
      (SIGSEGV)
      si_code: -6
      signal sent by tkill (sent by pid 4268, uid 5000)

Register Information
r0   = 0xbed294e4, r1   = 0x000030e4
r2   = 0x00000000, r3   = 0xb44d8940
r4   = 0xbed294e4, r5   = 0x00000000
r6   = 0x006a1f28, r7   = 0x003edaf8
r8   = 0xb44d8940, r9   = 0x000aec10
r10  = 0xb44d8940, fp   = 0xbed29cb8
ip   = 0xb44db77c, sp   = 0xbed294c0
lr   = 0xb42ecd7f, pc   = 0xb42ecd86
cpsr = 0x48000030

Memory Information
MemTotal:   797320 KB
MemFree:    298736 KB
Buffers:     17176 KB
Cached:     166144 KB
VmPeak:     226884 KB
VmSize:     163284 KB
VmLck:           0 KB
VmHWM:       75780 KB
VmRSS:       75728 KB
VmData:      87648 KB
VmStk:         136 KB
VmExe:          32 KB
VmLib:       44404 KB
VmPTE:         198 KB
VmSwap:          0 KB

Maps Information
00008000 00010000 r-xp /usr/bin/launchpad_preloading_preinitializing_daemon
00018000 000dc000 rw-p [heap]
000dc000 00921000 rw-p [heap]
ad596000 ad598000 r-xp /usr/lib/evas/modules/loaders/png/linux-gnueabi-armv7l-1.7.99/module.so
b06c4000 b06c9000 r-xp /usr/lib/libhaptic-module.so
b06fa000 b070b000 r-xp /usr/lib/scim-1.0/1.4.0/IMEngine/socket.so
b0714000 b0719000 r-xp /usr/lib/scim-1.0/1.4.0/Config/socket.so
b0c58000 b0c5b000 r-xp /usr/lib/bufmgr/libtbm_exynos4412.so.0.0.0
b24a3000 b24ee000 r-xp /usr/lib/libGLESv1_CM.so.1.1
b24f7000 b251f000 r-xp /usr/lib/evas/modules/engines/gl_x11/linux-gnueabi-armv7l-1.7.99/module.so
b2547000 b255b000 r-xp /usr/lib/libnetwork.so.0.0.0
b2564000 b2578000 r-xp /usr/lib/libwifi-direct.so.0.0
b2580000 b2588000 r-xp /usr/lib/libcapi-network-tethering.so.0.1.0
b2589000 b2592000 r-xp /usr/lib/libcapi-network-connection.so.0.1.3_18
b259a000 b265f000 r-xp /usr/lib/osp/libosp-net.so.1.2.2.0
b266d000 b268a000 r-xp /usr/lib/osp/libosp-image.so.1.2.2.0
b2693000 b269d000 r-xp /usr/lib/evas/modules/engines/software_generic/linux-gnueabi-armv7l-1.7.99/module.so
b26a5000 b2709000 r-xp /opt/usr/apps/ZPYDNnmVpf/bin/TizenProject.exe
b2715000 b2787000 r-xp /usr/lib/libosp-env-config.so.1.2.2.1
b278f000 b27c9000 r-xp /usr/lib/libpulsecommon-0.9.23.so
b27d2000 b27d6000 r-xp /usr/lib/libmmfsoundcommon.so.0.0.0
b27de000 b280f000 r-xp /usr/lib/libpulse.so.0.12.4
b2817000 b287a000 r-xp /usr/lib/libasound.so.2.0.0
b2884000 b2887000 r-xp /usr/lib/libpulse-simple.so.0.0.3
b288f000 b2893000 r-xp /usr/lib/libascenario-0.2.so.0.0.0
b289c000 b28b9000 r-xp /usr/lib/libavsysaudio.so.0.0.1
b28c1000 b28cf000 r-xp /usr/lib/libmmfsound.so.0.1.0
b28d7000 b2973000 r-xp /usr/lib/libgstreamer-0.10.so.0.30.0
b297f000 b29c0000 r-xp /usr/lib/libgstbase-0.10.so.0.30.0
b29c9000 b29d2000 r-xp /usr/lib/libgstapp-0.10.so.0.25.0
b29da000 b29e7000 r-xp /usr/lib/libgstinterfaces-0.10.so.0.25.0
b29f0000 b29f6000 r-xp /usr/lib/libUMP.so
b29fe000 b2a01000 r-xp /usr/lib/libmm_ta.so.0.0.0
b2a09000 b2a18000 r-xp /usr/lib/libICE.so.6.3.0
b2a22000 b2a27000 r-xp /usr/lib/libSM.so.6.0.1
b2a2f000 b2a30000 r-xp /usr/lib/libmmfkeysound.so.0.0.0
b2a38000 b2a40000 r-xp /usr/lib/libmmfcommon.so.0.0.0
b2a48000 b2a50000 r-xp /usr/lib/libaudio-session-mgr.so.0.0.0
b2a5b000 b2a5e000 r-xp /usr/lib/libmmfsession.so.0.0.0
b2a66000 b2aaa000 r-xp /usr/lib/libmmfplayer.so.0.0.0
b2ab3000 b2ac6000 r-xp /usr/lib/libEGL_platform.so
b2acf000 b2ba6000 r-xp /usr/lib/libMali.so
b2bb1000 b2bb7000 r-xp /usr/lib/libxcb-render.so.0.0.0
b2bbf000 b2bc0000 r-xp /usr/lib/libxcb-shm.so.0.0.0
b2bc9000 b2c07000 r-xp /usr/lib/libGLESv2.so.2.0
b2c0f000 b2c5a000 r-xp /usr/lib/libtiff.so.5.1.0
b2c65000 b2c8e000 r-xp /usr/lib/libturbojpeg.so
b2ca7000 b2cad000 r-xp /usr/lib/libmmutil_imgp.so.0.0.0
b2cb5000 b2cbb000 r-xp /usr/lib/libgif.so.4.1.6
b2cc3000 b2ce5000 r-xp /usr/lib/libavutil.so.51.73.101
b2cf4000 b2d22000 r-xp /usr/lib/libswscale.so.2.1.101
b2d2b000 b3022000 r-xp /usr/lib/libavcodec.so.54.59.100
b3349000 b3362000 r-xp /usr/lib/libpng12.so.0.50.0
b336b000 b3371000 r-xp /usr/lib/libfeedback.so.0.1.4
b3379000 b3385000 r-xp /usr/lib/libtts.so
b338d000 b33a4000 r-xp /usr/lib/libEGL.so.1.4
b33ad000 b3464000 r-xp /usr/lib/libcairo.so.2.11200.12
b346e000 b3488000 r-xp /usr/lib/osp/libosp-image-core.so.1.2.2.0
b3491000 b3d8c000 r-xp /usr/lib/osp/libosp-uifw.so.1.2.2.1
b3dff000 b3e04000 r-xp /usr/lib/libslp_devman_plugin.so
b3e0d000 b3e10000 r-xp /usr/lib/libsyspopup_caller.so.0.1.0
b3e18000 b3e1c000 r-xp /usr/lib/libsysman.so.0.2.0
b3e24000 b3e35000 r-xp /usr/lib/libsecurity-server-commons.so.1.0.0
b3e3e000 b3e40000 r-xp /usr/lib/libsystemd-daemon.so.0.0.1
b3e48000 b3e4a000 r-xp /usr/lib/libdeviced.so.0.1.0
b3e52000 b3e68000 r-xp /usr/lib/libpkgmgr_parser.so.0.1.0
b3e70000 b3e72000 r-xp /usr/lib/libpkgmgr_installer_status_broadcast_server.so.0.1.0
b3e7a000 b3e7d000 r-xp /usr/lib/libpkgmgr_installer_client.so.0.1.0
b3e85000 b3e88000 r-xp /usr/lib/libdevice-node.so.0.1
b3e90000 b3e94000 r-xp /usr/lib/libheynoti.so.0.0.2
b3e9c000 b3ee1000 r-xp /usr/lib/libsoup-2.4.so.1.5.0
b3eea000 b3eff000 r-xp /usr/lib/libsecurity-server-client.so.1.0.1
b3f08000 b3f0c000 r-xp /usr/lib/libcapi-system-info.so.0.2.0
b3f14000 b3f19000 r-xp /usr/lib/libcapi-system-system-settings.so.0.0.2
b3f21000 b3f22000 r-xp /usr/lib/libcapi-system-power.so.0.1.1
b3f2b000 b3f2e000 r-xp /usr/lib/libcapi-system-device.so.0.1.0
b3f36000 b3f39000 r-xp /usr/lib/libcapi-system-runtime-info.so.0.0.3
b3f42000 b3f45000 r-xp /usr/lib/libcapi-network-serial.so.0.0.8
b3f4d000 b3f4e000 r-xp /usr/lib/libcapi-content-mime-type.so.0.0.2
b3f56000 b3f64000 r-xp /usr/lib/libcapi-appfw-application.so.0.1.0
b3f6d000 b3f8f000 r-xp /usr/lib/libSLP-tapi.so.0.0.0
b3f97000 b3f9a000 r-xp /usr/lib/libuuid.so.1.3.0
b3fa3000 b3fc1000 r-xp /usr/lib/libpkgmgr-info.so.0.0.17
b3fc9000 b3fe0000 r-xp /usr/lib/libpkgmgr-client.so.0.1.68
b3fe9000 b3fea000 r-xp /usr/lib/libpmapi.so.1.2
b3ff2000 b3ffa000 r-xp /usr/lib/libminizip.so.1.0.0
b4002000 b400d000 r-xp /usr/lib/libmessage-port.so.1.2.2.1
b4015000 b40ed000 r-xp /usr/lib/libxml2.so.2.7.8
b40fa000 b4118000 r-xp /usr/lib/libpcre.so.0.0.1
b4120000 b4123000 r-xp /usr/lib/libiniparser.so.0
b412c000 b4130000 r-xp /usr/lib/libhaptic.so.0.1
b4138000 b4143000 r-xp /usr/lib/libcryptsvc.so.0.0.1
b4150000 b4155000 r-xp /usr/lib/libdevman.so.0.1
b415e000 b4162000 r-xp /usr/lib/libchromium.so.1.0
b416a000 b4170000 r-xp /usr/lib/libappsvc.so.0.1.0
b4178000 b4179000 r-xp /usr/lib/osp/libappinfo.so.1.2.2.1
b4189000 b418b000 r-xp /opt/usr/apps/ZPYDNnmVpf/bin/TizenProject
b4193000 b4199000 r-xp /usr/lib/libalarm.so.0.0.0
b41a2000 b41b4000 r-xp /usr/lib/libprivacy-manager-client.so.0.0.5
b41bc000 b44bb000 r-xp /usr/lib/osp/libosp-appfw.so.1.2.2.1
b44e2000 b44ec000 r-xp /lib/libnss_files-2.13.so
b44f5000 b44fe000 r-xp /lib/libnss_nis-2.13.so
b4507000 b4518000 r-xp /lib/libnsl-2.13.so
b4523000 b4529000 r-xp /lib/libnss_compat-2.13.so
b4532000 b453b000 r-xp /usr/lib/libcapi-security-privilege-manager.so.0.0.3
b4863000 b4874000 r-xp /usr/lib/libcom-core.so.0.0.1
b487c000 b487e000 r-xp /usr/lib/libdri2.so.0.0.0
b4886000 b488e000 r-xp /usr/lib/libdrm.so.2.4.0
b4896000 b489a000 r-xp /usr/lib/libtbm.so.1.0.0
b48a2000 b48a5000 r-xp /usr/lib/libXv.so.1.0.0
b48ad000 b4978000 r-xp /usr/lib/libscim-1.0.so.8.2.3
b498e000 b499e000 r-xp /usr/lib/libnotification.so.0.1.0
b49a6000 b49ca000 r-xp /usr/lib/ecore/immodules/libisf-imf-module.so
b49d3000 b49e3000 r-xp /lib/libresolv-2.13.so
b49e7000 b49e9000 r-xp /usr/lib/libgmodule-2.0.so.0.3200.3
b49f1000 b4b44000 r-xp /usr/lib/libcrypto.so.1.0.0
b4b62000 b4bae000 r-xp /usr/lib/libssl.so.1.0.0
b4bba000 b4be6000 r-xp /usr/lib/libidn.so.11.5.44
b4bef000 b4bf9000 r-xp /usr/lib/libcares.so.2.0.0
b4c01000 b4c18000 r-xp /lib/libexpat.so.1.5.2
b4c22000 b4c46000 r-xp /usr/lib/libicule.so.48.1
b4c4f000 b4c57000 r-xp /usr/lib/libsf_common.so
b4c5f000 b4cfa000 r-xp /usr/lib/libstdc++.so.6.0.14
b4d0d000 b4dea000 r-xp /usr/lib/libgio-2.0.so.0.3200.3
b4df5000 b4e1a000 r-xp /usr/lib/libexif.so.12.3.3
b4e2e000 b4e38000 r-xp /usr/lib/libethumb.so.1.7.99
b4e40000 b4e84000 r-xp /usr/lib/libsndfile.so.1.0.25
b4e92000 b4e94000 r-xp /usr/lib/libctxdata.so.0.0.0
b4e9c000 b4eaa000 r-xp /usr/lib/libremix.so.0.0.0
b4eb2000 b4eb3000 r-xp /usr/lib/libecore_imf_evas.so.1.7.99
b4ebb000 b4ed4000 r-xp /usr/lib/liblua-5.1.so
b4edd000 b4ee4000 r-xp /usr/lib/libembryo.so.1.7.99
b4eed000 b4ef0000 r-xp /usr/lib/libecore_input_evas.so.1.7.99
b4ef8000 b4f35000 r-xp /usr/lib/libcurl.so.4.3.0
b4f3f000 b4f43000 r-xp /usr/lib/libecore_ipc.so.1.7.99
b4f4c000 b4fb6000 r-xp /usr/lib/libpixman-1.so.0.28.2
b4fc3000 b4fe7000 r-xp /usr/lib/libfontconfig.so.1.5.0
b4ff0000 b504c000 r-xp /usr/lib/libharfbuzz.so.0.907.0
b505e000 b5072000 r-xp /usr/lib/libfribidi.so.0.3.1
b507a000 b50cf000 r-xp /usr/lib/libfreetype.so.6.8.1
b50da000 b50fe000 r-xp /usr/lib/libjpeg.so.8.0.2
b5116000 b512d000 r-xp /lib/libz.so.1.2.5
b5135000 b5142000 r-xp /usr/lib/libsensor.so.1.1.0
b514d000 b514f000 r-xp /usr/lib/libapp-checker.so.0.1.0
b5157000 b515d000 r-xp /usr/lib/libxdgmime.so.1.1.0
b6274000 b635c000 r-xp /usr/lib/libicuuc.so.48.1
b6369000 b6489000 r-xp /usr/lib/libicui18n.so.48.1
b6497000 b649a000 r-xp /usr/lib/libSLP-db-util.so.0.1.0
b64a2000 b64ab000 r-xp /usr/lib/libvconf.so.0.2.45
b64b3000 b64c1000 r-xp /usr/lib/libail.so.0.1.0
b64c9000 b64e1000 r-xp /usr/lib/libdbus-glib-1.so.2.2.2
b64e2000 b64e7000 r-xp /usr/lib/libffi.so.5.0.10
b64ef000 b64f0000 r-xp /usr/lib/libgthread-2.0.so.0.3200.3
b64f8000 b6502000 r-xp /usr/lib/libXext.so.6.4.0
b650b000 b650e000 r-xp /usr/lib/libXtst.so.6.1.0
b6516000 b651c000 r-xp /usr/lib/libXrender.so.1.3.0
b6524000 b652a000 r-xp /usr/lib/libXrandr.so.2.2.0
b6532000 b6533000 r-xp /usr/lib/libXinerama.so.1.0.0
b653c000 b6545000 r-xp /usr/lib/libXi.so.6.1.0
b654d000 b6550000 r-xp /usr/lib/libXfixes.so.3.1.0
b6558000 b655a000 r-xp /usr/lib/libXgesture.so.7.0.0
b6562000 b6564000 r-xp /usr/lib/libXcomposite.so.1.0.0
b656c000 b656d000 r-xp /usr/lib/libXdamage.so.1.1.0
b6576000 b657d000 r-xp /usr/lib/libXcursor.so.1.0.2
b6585000 b658d000 r-xp /usr/lib/libemotion.so.1.7.99
b6595000 b65b0000 r-xp /usr/lib/libecore_con.so.1.7.99
b65b9000 b65be000 r-xp /usr/lib/libecore_imf.so.1.7.99
b65c7000 b65cf000 r-xp /usr/lib/libethumb_client.so.1.7.99
b65d7000 b65d9000 r-xp /usr/lib/libefreet_trash.so.1.7.99
b65e1000 b65e5000 r-xp /usr/lib/libefreet_mime.so.1.7.99
b65ee000 b6604000 r-xp /usr/lib/libefreet.so.1.7.99
b660e000 b6617000 r-xp /usr/lib/libedbus.so.1.7.99
b661f000 b6624000 r-xp /usr/lib/libecore_fb.so.1.7.99
b662d000 b6689000 r-xp /usr/lib/libedje.so.1.7.99
b6693000 b66aa000 r-xp /usr/lib/libecore_input.so.1.7.99
b66c5000 b66ca000 r-xp /usr/lib/libecore_file.so.1.7.99
b66d2000 b66ef000 r-xp /usr/lib/libecore_evas.so.1.7.99
b66f8000 b6737000 r-xp /usr/lib/libeina.so.1.7.99
b6740000 b67ef000 r-xp /usr/lib/libevas.so.1.7.99
b6811000 b6824000 r-xp /usr/lib/libeet.so.1.7.99
b682d000 b6897000 r-xp /lib/libm-2.13.so
b68a3000 b68aa000 r-xp /usr/lib/libutilX.so.1.1.0
b68b2000 b68b7000 r-xp /usr/lib/libappcore-common.so.1.1
b68bf000 b68ca000 r-xp /usr/lib/libaul.so.0.1.0
b68d3000 b6907000 r-xp /usr/lib/libgobject-2.0.so.0.3200.3
b6910000 b6940000 r-xp /usr/lib/libecore_x.so.1.7.99
b6949000 b695e000 r-xp /usr/lib/libecore.so.1.7.99
b6975000 b6a95000 r-xp /usr/lib/libelementary.so.1.7.99
b6aa8000 b6aab000 r-xp /lib/libattr.so.1.1.0
b6ab3000 b6ab5000 r-xp /usr/lib/libXau.so.6.0.0
b6abd000 b6ac3000 r-xp /lib/librt-2.13.so
b6acc000 b6ad4000 r-xp /lib/libcrypt-2.13.so
b6b04000 b6b07000 r-xp /lib/libcap.so.2.21
b6b0f000 b6b11000 r-xp /usr/lib/libiri.so
b6b19000 b6b2e000 r-xp /usr/lib/libxcb.so.1.1.0
b6b36000 b6b41000 r-xp /lib/libunwind.so.8.0.1
b6b6f000 b6c8c000 r-xp /lib/libc-2.13.so
b6c9a000 b6ca3000 r-xp /lib/libgcc_s-4.5.3.so.1
b6cab000 b6cae000 r-xp /usr/lib/libsmack.so.1.0.0
b6cb6000 b6ce2000 r-xp /usr/lib/libdbus-1.so.3.7.2
b6ceb000 b6cef000 r-xp /usr/lib/libbundle.so.0.1.22
b6cf7000 b6cf9000 r-xp /lib/libdl-2.13.so
b6d02000 b6ddc000 r-xp /usr/lib/libglib-2.0.so.0.3200.3
b6de5000 b6e4f000 r-xp /usr/lib/libsqlite3.so.0.8.6
b6e59000 b6e66000 r-xp /usr/lib/libprivilege-control.so.0.0.2
b6e6f000 b6f55000 r-xp /usr/lib/libX11.so.6.3.0
b6f60000 b6f74000 r-xp /lib/libpthread-2.13.so
b6f84000 b6f88000 r-xp /usr/lib/libappcore-efl.so.1.1
b6f91000 b6f92000 r-xp /usr/lib/libdlog.so.0.0.0
b6f9a000 b6f9e000 r-xp /usr/lib/libsys-assert.so
b6fa6000 b6fc3000 r-xp /lib/ld-2.13.so
bed0b000 bed2c000 rwxp [stack]
End of Maps Information

Callstack Information (PID:4268)
Call Stack Count: 42
 0: Tizen::Base::String::String(Tizen::Base::String const&) + 0x19 (0xb42ecd86) [/usr/lib/osp/libosp-appfw.so] + 0x130d86
 1: Tizen::Base::String::operator=(Tizen::Base::String const&) + 0x12 (0xb42ee0cf) [/usr/lib/osp/libosp-appfw.so] + 0x1320cf
 2: EditPanel::OnActionPerformed(Tizen::Ui::Control const&, int) + 0xd94 (0xb26c6814) [/opt/apps/ZPYDNnmVpf/bin/TizenProject.exe] + 0x21814
 3: non-virtual thunk to EditPanel::OnActionPerformed(Tizen::Ui::Control const&, int) + 0x3c (0xb26c95cc) [/opt/apps/ZPYDNnmVpf/bin/TizenProject.exe] + 0x245cc
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
