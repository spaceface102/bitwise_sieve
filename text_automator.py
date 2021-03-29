nums = [
        0x828228a20a08a288,
        0x8828228a20a08a28,      0x28828228a20a08a2,
        0xa28828228a20a08a,      0x8a28828228a20a08,
        0x08a28828228a20a0,      0xa08a28828228a20a,
        0x0a08a28828228a20,      0x20a08a28828228a2,
        0xa20a08a28828228a,      0x8a20a08a28828228,
        0x28a20a08a2882822,      0x228a20a08a288282,
        0x8228a20a08a28828,      0x28228a20a08a2882,                     
        ]

for i in range(len(nums)):
    print(f"if (arraysize > {i+1}) sievearray[{i+1}] = {hex(nums[i])};")
