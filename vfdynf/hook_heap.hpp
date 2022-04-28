/*
    Copyright (c) Johnny Shaw. All rights reserved. 
*/
#pragma once

_Must_inspect_result_
_Ret_maybenull_
_Post_writable_byte_size_(Size)
PVOID
NTAPI
Hook_RtlAllocateHeap(
    _In_ PVOID HeapHandle,
    _In_opt_ ULONG Flags,
    _In_ SIZE_T Size
    );

PVOID
NTAPI
Hook_RtlReAllocateHeap(
    _In_ PVOID HeapHandle,
    _In_ ULONG Flags,
    _Frees_ptr_opt_ PVOID BaseAddress,
    _In_ SIZE_T Size
    );

_Success_(return != NULL)
_Post_writable_byte_size_(dwBytes)
DECLSPEC_ALLOCATOR
HGLOBAL
WINAPI
Hook_GlobalAlloc(
    _In_ UINT uFlags,
    _In_ SIZE_T dwBytes
    );

_Ret_reallocated_bytes_(hMem, dwBytes)
DECLSPEC_ALLOCATOR
HGLOBAL
WINAPI
Hook_GlobalReAlloc(
    _Frees_ptr_ HGLOBAL hMem,
    _In_ SIZE_T dwBytes,
    _In_ UINT uFlags
    );

_Success_(return != NULL)
_Post_writable_byte_size_(uBytes)
DECLSPEC_ALLOCATOR
HLOCAL
WINAPI
Hook_LocalAlloc(
    _In_ UINT uFlags,
    _In_ SIZE_T uBytes
    );

_Ret_reallocated_bytes_(hMem, uBytes)
DECLSPEC_ALLOCATOR
HLOCAL
WINAPI
Hook_LocalReAlloc(
    _Frees_ptr_opt_ HLOCAL hMem,
    _In_ SIZE_T uBytes,
    _In_ UINT uFlags
    );
