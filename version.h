/***********************IMPORTANT NPCAP LICENSE TERMS***********************
 *
 * Npcap (https://npcap.com) is a Windows packet sniffing driver and library and
 * is copyright (c) 2013-2025 by Nmap Software LLC ("The Nmap Project").  All
 * rights reserved.
 *
 * Even though Npcap source code is publicly available for review, it is not
 * open source software and may not be redistributed or used in other software
 * without special permission from the Nmap Project. The standard (free) version
 * is usually limited to installation on five systems. For more details, see the
 * LICENSE file included with Npcap and also available at
 * https://github.com/nmap/npcap/blob/master/LICENSE. This header file
 * summarizes a few important aspects of the Npcap license, but is not a
 * substitute for that full Npcap license agreement.
 *
 * We fund the Npcap project by selling two types of commercial licenses to a
 * special Npcap OEM edition:
 *
 * 1) The Npcap OEM Redistribution License allows companies distribute Npcap OEM
 * within their products. Licensees generally use the Npcap OEM silent
 * installer, ensuring a seamless experience for end users. Licensees may choose
 * between a perpetual unlimited license or a quarterly term license, along with
 * options for commercial support and updates. Prices and details:
 * https://npcap.com/oem/redist.html
 *
 * 2) The Npcap OEM Internal-Use License is for organizations that wish to use
 * Npcap OEM internally, without redistribution outside their organization. This
 * allows them to bypass the 5-system usage cap of the Npcap free edition. It
 * includes commercial support and update options, and provides the extra Npcap
 * OEM features such as the silent installer for automated deployment. Prices
 * and details: https://npcap.com/oem/internal.html
 *
 * Both of these licenses include updates and support as well as a warranty.
 * Npcap OEM also includes a silent installer for unattended installation.
 * Further details about Npcap OEM are available from https://npcap.com/oem/,
 * and you are also welcome to contact us at sales@nmap.com to ask any questions
 * or set up a license for your organization.
 *
 * Free and open source software producers are also welcome to contact us for
 * redistribution requests. However, we normally recommend that such authors
 * instead ask your users to download and install Npcap themselves. It will be
 * free for them if they need 5 or fewer copies.
 *
 * If the Nmap Project (directly or through one of our commercial licensing
 * customers) has granted you additional rights to Npcap or Npcap OEM, those
 * additional rights take precedence where they conflict with the terms of the
 * license agreement.
 *
 * Since the Npcap source code is available for download and review, users
 * sometimes contribute code patches to fix bugs or add new features. By sending
 * these changes to the Nmap Project (including through direct email or our
 * mailing lists or submitting pull requests through our source code
 * repository), it is understood unless you specify otherwise that you are
 * offering the Nmap Project the unlimited, non-exclusive right to reuse,
 * modify, and relicense your code contribution so that we may (but are not
 * obligated to) incorporate it into Npcap. If you wish to specify special
 * license conditions or restrictions on your contributions, just say so when
 * you send them.
 *
 * This software is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. Warranty rights and commercial support are
 * available for the OEM Edition described above.
 *
 * Other copyright notices and attribution may appear below this license header.
 * We have kept those for attribution purposes, but any license terms granted by
 * those notices apply only to their original work, and not to any changes made
 * by the Nmap Project or to this entire file.
 *
 ***************************************************************************/
/*{{NO_DEPENDENCIES}}
 * Microsoft Developer Studio generated include file.
 *
 *
 * 3.1.0.24   -->  WinPcap  3.1 beta4
 * 3.1.0.27   -->  WinPcap  3.1 RTM
 * 3.2.0.29	  -->  WinPcap  3.2 alpha1
 * 4.0.0.374  -->  WinPcap  4.0 alpha1
 * 4.0.0.592  -->  WinPcap  4.0 beta1
 * 4.0.0.655  -->  WinPcap  4.0 beta2
 * 4.0.0.703  -->  WinPcap  4.0 beta3
 * 4.0.0.755  -->  WinPcap  4.0 RTM
 * 4.1.0.902  -->  WinPcap  4.1 beta
 * 4.1.0.1048 -->  WinPcap  4.1 beta2
 * 4.1.0.1124 -->  WinPcap  4.1 beta3
 * 4.1.0.1237 -->  WinPcap  4.1 beta4
 * 4.1.0.1452 -->  WinPcap  4.1 beta5
 * 4.1.0.1752 -->  WinPcap  4.1 RTM
 * 4.1.0.1753 -->  WinPcap  4.1.1 RTM
 * 4.1.0.2001 -->  WinPcap  4.1.2 RTM
 * 4.1.0.2980 -->  WinPcap  4.1.3 RTM
 * 4.1.0.3001 -->  WinPcap  4.1.3 RTM (NDIS6)
 * 0.1.0.710  -->  Npcap  0.01 beta (NDIS6)
 * 0.2.0.718  -->  Npcap  0.02 beta
 * 0.3.0.727  -->  Npcap  0.03 beta
 * 0.4.0.815  -->  Npcap  0.04 beta
 * 0.5.0.912  -->  Npcap  0.05 beta
 * 0.6.0.301  -->  Npcap  0.06 beta
 * 0.7.0.424  -->  Npcap  0.07 beta
 * 0.8.0.724  -->  Npcap  0.08 beta
 * 0.9.0.831  -->  Npcap  0.09 beta
 * 0.10.0.921 -->  Npcap  0.10 beta
 * 0.11.0.1121-->  Npcap  0.11 beta
 * 0.78.0.1123-->  Npcap  0.78 beta
 */

#define /*
 !define /**/ WINPCAP_MAJOR				5
#define /*
 !define /**/ WINPCAP_MINOR				1
/* WINPCAP_REV should be less than 256 to fit in UCHAR */
#define /*
 !define /**/ WINPCAP_REV				83
#define /*
 !define /**/ WINPCAP_BUILD				730
#define /*
 !define /**/ WINPCAP_VER_STRING		"1.83"
#define /*
 !define /**/ NPCAP_SDK_VERSION "1.15"

#define WINPCAP_COMPANY_NAME 			"Nmap Software LLC"

#ifdef RC_INVOKED
/* NPFInstall.exe uses the VersionInfo.ProductName to identify Npcap DLLs, so
 * we can't put OEM name in there unless we change that. */
#define WINPCAP_PRODUCT_NAME "Npcap"
#else

#ifdef /*
 !ifdef /**/ NPCAP_OEM
#ifdef /*
 !ifdef /**/ NPCAP_READ_ONLY
#define /*
 !define /**/ WINPCAP_PRODUCT_NAME 			"Npcap OEM RO"
#else /*
 !else /**/
#define /*
 !define /**/ WINPCAP_PRODUCT_NAME 			"Npcap OEM"
#endif /*
 !endif /**/
#else /*
 !else /**/
#define /*
 !define /**/ WINPCAP_PRODUCT_NAME 			"Npcap"
#endif /*
 !endif /**/

#endif /* RC_INVOKED */

#define WINPCAP_COPYRIGHT_STRING 		"Copyright (c) 2025, Nmap Software LLC.  All rights reserved."
#define /*
 !define /**/ WINPCAP_INSTALLERHELPER_COPYRIGHT_STRING "Copyright (c) 2025, Nmap Software LLC.  All rights reserved."
#define WINPCAP_RPCAPD_COPYRIGHT_STRING "Copyright (c) 2025, Nmap Software LLC.  All rights reserved."

#define WINPCAP_BUILD_DESCRIPTION 		""
#define WINPCAP_PRIVATE_BUILD			""
