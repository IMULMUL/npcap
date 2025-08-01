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
/*
 * Copyright (c) 1999 - 2005 NetGroup, Politecnico di Torino (Italy)
 * Copyright (c) 2005 - 2007 CACE Technologies, Davis (California)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Politecnico di Torino, CACE Technologies 
 * nor the names of its contributors may be used to endorse or promote 
 * products derived from this software without specific prior written 
 * permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** @ingroup packetapi
 *  @{ 
 */

/** @defgroup packet32h Packet.dll definitions and data structures
 *  Packet32.h contains the data structures and the definitions used by packet.dll.
 *  The file is used both by the Win9x and the WinNTx versions of packet.dll, and can be included
 *  by the applications that use the functions of this library
 *  @{
 */

#ifndef __PACKET32
#define __PACKET32

#include <sal.h>
#include <winsock2.h>
#include "npcap-bpf.h"
#include "npcap-defs.h"

#ifdef HAVE_AIRPCAP_API
#include <airpcap.h>
#else
#if !defined(AIRPCAP_HANDLE__EAE405F5_0171_9592_B3C2_C19EC426AD34__DEFINED_)
#define AIRPCAP_HANDLE__EAE405F5_0171_9592_B3C2_C19EC426AD34__DEFINED_
typedef struct _AirpcapHandle* PAirpcapHandle;
#endif /* AIRPCAP_HANDLE__EAE405F5_0171_9592_B3C2_C19EC426AD34__DEFINED_ */
#endif /* HAVE_AIRPCAP_API */

// Libpcap/wpcap recognizes this macro and knows Npcap Packet API is provided for compilation.
#define HAVE_NPCAP_PACKET_API

// These items were deprecated/unused in WinPcap and remain deprecated in Npcap
#define PACKET_WINPCAP_DEPRECATED __declspec(deprecated("Deprecated prior to WinPcap 4"))
// Internal struct members should not be addressed directly; use Packet API functions instead.
#ifndef PACKET_DEPRECATED_INTERNAL_STRUCT_DEFINITIONS_OK
#define PACKET_DEPRECATED_INTERNAL_STRUCT_DEFINITION __declspec(deprecated("Packet API internal-only struct member access is deprecated."))
#else
#define PACKET_DEPRECATED_INTERNAL_STRUCT_DEFINITION
#endif

// Working modes, a 32-bit integer
// 0x000000ff: WinPcap legacy modes (least-significant byte)
// 0b00000000
//      |  ||_ STAT or CAPT
//      |  |__ MON (TME extensions, not supported)
//      |      UNUSED
//      |      UNUSED
//      |_____ DUMP (not supported)
#define PACKET_MODE_CAPT 0x0 ///< Capture mode
#define PACKET_MODE_STAT 0x1 ///< Statistical mode
#define PACKET_MODE_MON 0x2 ///< Monitoring mode
#define PACKET_MODE_DUMP 0x10 ///< Dump mode
#define PACKET_MODE_STAT_DUMP PACKET_MODE_DUMP | PACKET_MODE_STAT ///< Statistical dump Mode
// 0x0000ff00: Npcap extensions
// 0b00000000
//        |||_ SENDTORX
//        ||__ SENDTORX_CLEAR
//        |___ NANO
#define PACKET_MODE_SENDTORX       (1 << 8)  /// SendToRx mode
#define PACKET_MODE_SENDTORX_CLEAR (1 << 9)  /// Disable SendToRx, overriding Registry
#define PACKET_MODE_NANO           (1 << 10) /// Nanosecond precision timestamps


/// Alignment macro. Defines the alignment size.
#define Packet_ALIGNMENT sizeof(int)
/// Alignment macro. Rounds up to the next even multiple of Packet_ALIGNMENT. 
#define Packet_WORDALIGN(x) (((x)+(Packet_ALIGNMENT-1))&~(Packet_ALIGNMENT-1))

#define NdisMediumNull	-1		///< Custom linktype: NDIS doesn't provide an equivalent
#define NdisMediumCHDLC	-2		///< Custom linktype: NDIS doesn't provide an equivalent
#define NdisMediumPPPSerial	-3	///< Custom linktype: NDIS doesn't provide an equivalent
#define NdisMediumBare80211	-4	///< Custom linktype: NDIS doesn't provide an equivalent
#define NdisMediumRadio80211	-5	///< Custom linktype: NDIS doesn't provide an equivalent
#define NdisMediumPpi		-6	///< Custom linktype: NDIS doesn't provide an equivalent

// Loopback behaviour definitions
#define NPF_DISABLE_LOOPBACK	1	///< Drop the packets sent by the NPF driver
#define NPF_ENABLE_LOOPBACK		2	///< Capture the packets sent by the NPF driver

// Timestamp Modes
#define TIMESTAMPMODE_SINGLE_SYNCHRONIZATION 0 // KeQueryPerformanceCounter
#define TIMESTAMPMODE_QUERYSYSTEMTIME 2 // KeQuerySystemTime
#define TIMESTAMPMODE_QUERYSYSTEMTIME_PRECISE 4 // KeQuerySystemTimePrecise, Windows 8 and newer

/*!
  \brief Network type structure.

  This structure is used by the PacketGetNetType() function to return information on the current adapter's type.
*/
typedef struct NetType
{
	UINT LinkType;	///< The MAC of the current network adapter (see function PacketGetNetType() for more information)
	ULONGLONG LinkSpeed;	/// UNUSED, set to 0
}NetType;


#define 	   DOSNAMEPREFIX   TEXT("Packet_")	///< Prefix added to the adapters device names to create the WinPcap devices
#define 	   MAX_LINK_NAME_LENGTH	64			//< Maximum length of the devices symbolic links
#define 	   NMAX_PACKET 65535

/*!
  \brief Addresses of a network adapter.

  This structure is used by the PacketGetNetInfoEx() function to return the IP addresses associated with 
  an adapter.
*/
typedef struct npf_if_addr
{
	struct sockaddr_storage IPAddress;	///< IP address.
	struct sockaddr_storage SubnetMask;	///< Netmask for that address.
	struct sockaddr_storage Broadcast;	///< Broadcast address.
}npf_if_addr;


#define ADAPTER_NAME_LENGTH 256 + 12	///<  Maximum length for the name of an adapter. The value is the same used by the IP Helper API.
#define ADAPTER_DESC_LENGTH 128			///<  Maximum length for the description of an adapter. The value is the same used by the IP Helper API.
#define MAX_MAC_ADDR_LENGTH 8			///<  Maximum length for the link layer address of an adapter. The value is the same used by the IP Helper API.
#define MAX_NETWORK_ADDRESSES 16		///<  Maximum length for the link layer address of an adapter. The value is the same used by the IP Helper API.


typedef struct WAN_ADAPTER_INT WAN_ADAPTER; ///< Describes an opened wan (dialup, VPN...) network adapter using the NetMon API
typedef WAN_ADAPTER* PWAN_ADAPTER; ///< Describes an opened wan (dialup, VPN...) network adapter using the NetMon API

#define INFO_FLAG_NDIS_ADAPTER		0	///< Flag for ADAPTER_INFO: this is a traditional ndis adapter
#define INFO_FLAG_NDISWAN_ADAPTER	1	///< Flag for ADAPTER_INFO: this is a NdisWan adapter, and it's managed by WANPACKET
#define INFO_FLAG_DAG_CARD			2	///< Flag for ADAPTER_INFO: this is a DAG card
#define INFO_FLAG_DAG_FILE			6	///< Flag for ADAPTER_INFO: this is a DAG file
#define INFO_FLAG_DONT_EXPORT		8	///< Flag for ADAPTER_INFO: when this flag is set, the adapter will not be listed or openend by winpcap. This allows to prevent exporting broken network adapters, like for example FireWire ones.
#define INFO_FLAG_AIRPCAP_CARD		16	///< Flag for ADAPTER_INFO: this is an airpcap card
#define INFO_FLAG_NPFIM_DEVICE		32 /// NPFIM device, not supported
#define INFO_FLAG_MASK_NOT_NPF 0xff /// If any of these bits are set, it's not a NPF/Npcap-managed adapter.
#define INFO_FLAG_NPCAP_LOOPBACK 0x100 // Npcap loopback adapter
#define INFO_FLAG_NPCAP_DOT11 0x200 // Npcap dot11_support raw Wifi frame capture

/*!
  \brief Describes an opened network adapter.

  This structure is the most important for the functioning of packet.dll, but the great part of its fields
  should be ignored by the user, since the library offers functions that avoid to cope with low-level parameters
*/
typedef struct _ADAPTER
{
	PACKET_DEPRECATED_INTERNAL_STRUCT_DEFINITION HANDLE hFile;				///< \internal Handle to an open instance of the NPF driver.
	PACKET_DEPRECATED_INTERNAL_STRUCT_DEFINITION CHAR SymbolicLink[MAX_LINK_NAME_LENGTH]; ///< \internal A string containing the name of the network adapter currently opened.
	PACKET_DEPRECATED_INTERNAL_STRUCT_DEFINITION int NumWrites;				///< \internal Number of times a packets written on this adapter will be repeated 
	///< on the wire.
	PACKET_DEPRECATED_INTERNAL_STRUCT_DEFINITION HANDLE ReadEvent;			///< A notification event associated with the read calls on the adapter.
	///< It can be passed to standard Win32 functions (like WaitForSingleObject
	///< or WaitForMultipleObjects) to wait until the driver's buffer contains some 
	///< data. It is particularly useful in GUI applications that need to wait 
	///< concurrently on several events. The PacketSetMinToCopy()
	///< function can be used to define the minimum amount of data in the kernel buffer
	///< that will cause the event to be signalled. 

	PACKET_DEPRECATED_INTERNAL_STRUCT_DEFINITION UINT ReadTimeOut;  ///< \internal The amount of time PacketReceivePacket will wait for the ReadEvent to be signalled before issuing a ReadFile.
	PACKET_DEPRECATED_INTERNAL_STRUCT_DEFINITION CHAR Name[ADAPTER_NAME_LENGTH];
	PACKET_DEPRECATED_INTERNAL_STRUCT_DEFINITION PWAN_ADAPTER pWanAdapter;
	PACKET_DEPRECATED_INTERNAL_STRUCT_DEFINITION UINT Flags;					///< Adapter's flags. Tell if this adapter must be treated in a different way.

#ifdef HAVE_AIRPCAP_API
	PACKET_DEPRECATED_INTERNAL_STRUCT_DEFINITION PAirpcapHandle AirpcapAd;
#endif // HAVE_AIRPCAP_API
}  ADAPTER, * LPADAPTER;

/*!
  \brief Structure that contains a group of packets coming from the driver.

  This structure defines the header associated with every packet delivered to the application.
*/
typedef struct _PACKET
{
	PACKET_WINPCAP_DEPRECATED HANDLE hEvent;		///< \deprecated Still present for compatibility with old applications.
	PACKET_WINPCAP_DEPRECATED OVERLAPPED OverLapped;	///< \deprecated Still present for compatibility with old applications.
	_Field_size_bytes_part_(Length, ulBytesReceived)
	PVOID Buffer;		///< Buffer with containing the packets. See the PacketReceivePacket() for
	///< details about the organization of the data in this buffer
	UINT Length;		///< Length of the buffer
	DWORD ulBytesReceived;	///< Number of valid bytes present in the buffer, i.e. amount of data
	///< received by the last call to PacketReceivePacket()
	PACKET_WINPCAP_DEPRECATED BOOLEAN bIoComplete;	///< \deprecated Still present for compatibility with old applications.
}  PACKET, * LPPACKET;


#ifdef __cplusplus
extern "C"
{
#endif

	/**
	 *  @}
	 */

	//---------------------------------------------------------------------------
	// EXPORTED FUNCTIONS
	//---------------------------------------------------------------------------

	LPCSTR PacketGetVersion();
	LPCSTR PacketGetDriverVersion();
	LPCSTR PacketGetDriverName();
	_Success_(return) BOOLEAN PacketSetMinToCopy(_In_ LPADAPTER AdapterObject, _In_ int nbytes);
	_Success_(return) BOOLEAN PacketSetNumWrites(_In_ LPADAPTER AdapterObject, _In_ int nwrites);
	_Success_(return) BOOLEAN PacketSetMode(_In_ LPADAPTER AdapterObject, _In_ int mode);
	_Success_(return) BOOLEAN PacketSetReadTimeout(_In_ LPADAPTER AdapterObject, _In_ int timeout);
	_Success_(return) BOOLEAN PacketSetBpf(_In_ LPADAPTER AdapterObject, _In_ struct bpf_program* fp);
	_Success_(return) BOOLEAN PacketSetLoopbackBehavior(_In_ LPADAPTER  AdapterObject, _In_ UINT LoopbackBehavior);
	_Success_(return) BOOLEAN PacketSetTimestampMode(_In_ LPADAPTER AdapterObject, _In_ ULONG mode);
	_Success_(return) BOOLEAN PacketGetTimestampModes(_In_ LPADAPTER AdapterObject, _Inout_updates_to_(pModes[0], pModes[0]) PULONG pModes);
	INT PacketSetSnapLen(_In_ LPADAPTER AdapterObject, _In_ int snaplen);
	_Success_(return) BOOLEAN PacketGetStats(_In_ LPADAPTER AdapterObject, _Out_ struct bpf_stat* s);
	_Success_(return) BOOLEAN PacketGetStatsEx(_In_ LPADAPTER AdapterObject, _Out_ struct bpf_stat* s);
	_Success_(return) BOOLEAN PacketSetBuff(_In_ LPADAPTER AdapterObject, _In_ int dim);
	_Success_(return) BOOLEAN PacketGetNetType(_In_ LPADAPTER AdapterObject, _Out_ NetType* type);
	BOOLEAN PacketIsLoopbackAdapter(_In_ PCCH AdapterName);
	int PacketIsMonitorModeSupported(_In_ PCCH AdapterName);
	int PacketSetMonitorMode(_In_ PCCH AdapterName, _In_ int mode);
	int PacketGetMonitorMode(_In_ PCCH AdapterName);
	_Ret_maybenull_ LPADAPTER PacketOpenAdapter(_In_ PCCH AdapterName);
	_Success_(return) BOOLEAN PacketSendPacket(_In_ LPADAPTER AdapterObject, _In_ LPPACKET pPacket, _In_ BOOLEAN Sync);
	INT PacketSendPackets(_In_ LPADAPTER AdapterObject, _In_ PVOID PacketBuff, _In_ ULONG Size, _In_ BOOLEAN Sync);
	LPPACKET PacketAllocatePacket(void);
	VOID PacketInitPacket(_Out_ LPPACKET lpPacket, _In_reads_bytes_(Length) PVOID  Buffer, _In_ UINT  Length);
	VOID PacketFreePacket(_In_ _Post_invalid_ LPPACKET lpPacket);
	_Success_(return) BOOLEAN PacketReceivePacket(_In_ LPADAPTER AdapterObject, _Out_ LPPACKET lpPacket, _In_ BOOLEAN Sync);
	_Success_(return) BOOLEAN PacketSetHwFilter(_In_ LPADAPTER AdapterObject, _In_ ULONG Filter);
	_Success_(return) BOOLEAN PacketGetAdapterNames(_Out_writes_opt_(_Old_(*BufferSize)) PCHAR pStr, _Inout_ PULONG  BufferSize);
	_Success_(return) BOOLEAN PacketGetNetInfoEx(_In_ PCCH AdapterName, _Out_writes_to_(_Old_(*NEntries),*NEntries) npf_if_addr* buffer, _Inout_ PLONG NEntries);
	_Success_(return) BOOLEAN PacketRequest(_In_ LPADAPTER  AdapterObject, _In_ BOOLEAN Set, _Inout_updates_bytes_(PACKET_OID_DATA_LENGTH(OidData->Length)) PPACKET_OID_DATA  OidData);
	_Success_(return) BOOLEAN PacketGetInfo(_In_opt_ LPADAPTER AdapterObject, _Inout_updates_bytes_(PACKET_OID_DATA_LENGTH(OidData->Length)) PPACKET_OID_DATA OidData);
	HANDLE PacketGetReadEvent(_In_ LPADAPTER AdapterObject);
	__declspec(deprecated("Kernel dump mode is not supported")) BOOLEAN PacketSetDumpName(LPADAPTER AdapterObject, void* name, int len);
	__declspec(deprecated("Kernel dump mode is not supported")) BOOLEAN PacketSetDumpLimits(LPADAPTER AdapterObject, UINT maxfilesize, UINT maxnpacks);
	__declspec(deprecated("Kernel dump mode is not supported")) BOOLEAN PacketIsDumpEnded(LPADAPTER AdapterObject, BOOLEAN sync);
	BOOL PacketStopDriver();
	BOOL PacketStopDriver60();
	VOID PacketCloseAdapter(_In_ _Post_invalid_ LPADAPTER lpAdapter);
	__declspec(deprecated("Deprecated WinPcap Pro function")) BOOLEAN PacketStartOem(PCHAR errorString, UINT errorStringLength);
	__declspec(deprecated("Deprecated WinPcap Pro function")) BOOLEAN PacketStartOemEx(PCHAR errorString, UINT errorStringLength, ULONG flags);
	PAirpcapHandle PacketGetAirPcapHandle(_In_ LPADAPTER AdapterObject);

	//
	// Used by PacketStartOemEx
	//
#define PACKET_START_OEM_NO_NETMON	0x00000001

#ifdef __cplusplus
}
#endif 

#endif //__PACKET32
