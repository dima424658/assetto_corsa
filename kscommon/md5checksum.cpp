#include "md5checksum.h
MD5CheckSum *MD5CheckSum::finalize(MD5CheckSum *this)
{
  unsigned int v2; // edx
  char *v3; // eax
  unsigned __int8 v4; // cl
  int v5; // ecx
  unsigned int v6; // eax
  unsigned __int8 *v7; // ecx
  int v8; // edi
  char *v9; // edx
  unsigned __int8 v10; // al
  unsigned __int8 bits[8]; // [esp+4h] [ebp-Ch] BYREF

  if ( !this->finalized )
  {
    v2 = 0;
    v3 = (char *)this->count + 2;
    do
    {
      v4 = *(v3 - 2);
      v3 += 4;
      bits[v2] = v4;
      bits[v2 + 1] = *(v3 - 5);
      bits[v2 + 2] = *(v3 - 4);
      bits[v2 + 3] = *(v3 - 3);
      v2 += 4;
    }
    while ( v2 < 8 );
    v5 = 56;
    v6 = (this->count[0] >> 3) & 0x3F;
    if ( v6 >= 0x38 )
      v5 = 120;
    MD5CheckSum::update(this, padding, v5 - v6);
    MD5CheckSum::update(this, bits, 8u);
    v7 = &this->digest[1];
    v8 = 4;
    v9 = (char *)this->state + 2;
    do
    {
      v10 = *(v9 - 2);
      v9 += 4;
      *(v7 - 1) = v10;
      v7 += 4;
      *(v7 - 4) = *(v9 - 5);
      *(v7 - 3) = *(v9 - 4);
      *(v7 - 2) = *(v9 - 3);
      --v8;
    }
    while ( v8 );
    memset(this->buffer, 0, sizeof(this->buffer));
    *(_QWORD *)this->count = 0i64;
    this->finalized = 1;
  }
  return this;
}
std::wstring *MD5CheckSum::hexdigest(MD5CheckSum *this, std::wstring *result)
{
  int v3; // esi
  wchar_t *v4; // edi
  unsigned int v5; // ecx
  wchar_t buf[33]; // [esp+Ch] [ebp-48h] BYREF

  if ( this->finalized )
  {
    v3 = 0;
    v4 = buf;
    do
    {
      swprintf_1(v4, 3u, L"%02x", this->digest[v3++]);
      v4 += 2;
    }
    while ( v3 < 16 );
    result->_Myres = 7;
    buf[32] = 0;
    result->_Mysize = 0;
    result->_Bx._Buf[0] = 0;
    if ( buf[0] )
      v5 = wcslen(buf);
    else
      v5 = 0;
    std::wstring::assign(result, buf, v5);
  }
  else
  {
    result->_Myres = 7;
    result->_Mysize = 0;
    result->_Bx._Buf[0] = 0;
    std::wstring::assign(result, word_17BE9D8, 0);
  }
  return result;
}
void MD5CheckSum::transform(MD5CheckSum *this, const unsigned __int8 *block)
{
  unsigned int v2; // ebx
  unsigned int v3; // ebp
  unsigned int *v4; // esi
  const unsigned __int8 *v5; // eax
  int v6; // edi
  int v7; // edx
  int v8; // ecx
  unsigned int v9; // edx
  unsigned int v10; // esi
  unsigned int v11; // edi
  unsigned int v12; // ebx
  unsigned int v13; // edx
  unsigned int v14; // esi
  unsigned int v15; // edi
  unsigned int v16; // ebx
  unsigned int v17; // edx
  int v18; // esi
  int v19; // ebp
  int v20; // edi
  int v21; // ebp
  int v22; // ebx
  int v23; // edi
  int v24; // esi
  int v25; // edx
  int v26; // ebx
  int v27; // edi
  int v28; // esi
  int v29; // edx
  int v30; // ebx
  int v31; // edi
  int v32; // esi
  int v33; // ebp
  int v34; // ebx
  int v35; // edi
  int v36; // edx
  int v37; // esi
  int v38; // edi
  int v39; // ebx
  int v40; // edx
  int v41; // esi
  int v42; // edi
  int v43; // ebx
  int v44; // edx
  int v45; // esi
  int v46; // edi
  int v47; // ebx
  int v48; // ebp
  int v49; // esi
  int v50; // edi
  int v51; // edx
  int v52; // ecx
  int v53; // esi
  int v54; // edi
  int v55; // edx
  int v56; // ecx
  int v57; // esi
  int v58; // edi
  int v59; // edx
  int v60; // ecx
  int v61; // esi
  int v62; // edi
  int v63; // edx
  int v64; // ecx
  int v65; // ebx
  int v66; // edi
  int v67; // ebp
  int v68; // esi
  int v69; // edx
  int v70; // ecx
  unsigned int v71; // [esp+10h] [ebp-58h]
  int v72; // [esp+10h] [ebp-58h]
  int v73; // [esp+14h] [ebp-54h]
  int v74; // [esp+14h] [ebp-54h]
  unsigned int v75; // [esp+18h] [ebp-50h]
  int v76; // [esp+1Ch] [ebp-4Ch]
  unsigned int x[16]; // [esp+24h] [ebp-44h] BYREF

  v2 = this->state[1];
  v3 = this->state[2];
  v71 = this->state[3];
  v4 = x;
  v75 = this->state[0];
  v5 = block + 2;
  v6 = 16;
  do
  {
    v7 = v5[1];
    ++v4;
    v8 = *v5;
    v5 += 4;
    *(v4 - 1) = *(v5 - 6) | ((*(v5 - 5) | ((v8 | (v7 << 8)) << 8)) << 8);
    --v6;
  }
  while ( v6 );
  v9 = v2 + __ROL4__(x[0] + (v2 & v3 | v71 & ~v2) + v75 - 680876936, 7);
  v10 = v9 + __ROL4__(x[1] + (v9 & v2 | v3 & ~v9) + v71 - 389564586, 12);
  v11 = v10 + __ROR4__(x[2] + (v9 & v10 | v2 & ~v10) + v3 + 606105819, 15);
  v12 = v11 + __ROR4__(x[3] + (v11 & v10 | v9 & ~v11) + v2 - 1044525330, 10);
  v13 = v12 + __ROL4__(x[4] + (v12 & v11 | v10 & ~v12) - 176418897 + v9, 7);
  v14 = v13 + __ROL4__(x[5] + (v13 & v12 | v11 & ~v13) + 1200080426 + v10, 12);
  v15 = v14 + __ROR4__(x[6] + (v13 & v14 | v12 & ~v14) - 1473231341 + v11, 15);
  v16 = v15 + __ROR4__(x[7] + (v15 & v14 | v13 & ~v15) - 45705983 + v12, 10);
  v17 = v16 + __ROL4__(x[8] + (v16 & v15 | v14 & ~v16) + 1770035416 + v13, 7);
  v18 = v17 + __ROL4__(x[9] + (v17 & v16 | v15 & ~v17) - 1958414417 + v14, 12);
  v19 = __ROR4__(x[10] + (v17 & v18 | v16 & ~v18) + v15 - 42063, 15);
  v72 = v18 + v19;
  v76 = v18 + v19 + __ROR4__(x[11] + (v72 & v18 | v17 & ~v72) - 1990404162 + v16, 10);
  v20 = __ROL4__(x[12] + (v76 & (v18 + v19) | v18 & ~v76) + v17 + 1804603682, 7);
  v73 = v76 + v20;
  v21 = v76 + v20 + __ROL4__(x[13] + (v73 & v76 | (v18 + v19) & ~v73) + v18 - 40341101, 12);
  v22 = v21 + __ROR4__(x[14] + ((v76 + v20) & v21 | v76 & ~v21) + v72 - 1502002290, 15);
  v23 = v22 + __ROR4__(x[15] + (v22 & v21 | (v76 + v20) & ~v22) + v76 + 1236535329, 10);
  v24 = v23 + __ROL4__(v73 - 165796510 + x[1] + (v23 & v21 | v22 & ~v21), 5);
  v25 = v24 + __ROL4__(v21 + x[6] + (v24 & v22 | v23 & ~v22) - 1069501632, 9);
  v26 = v25 + __ROL4__(x[11] + (v23 & v25 | v24 & ~v23) + 643717713 + v22, 14);
  v27 = v26 + __ROR4__(x[0] + (v24 & v26 | v25 & ~v24) - 373897302 + v23, 12);
  v28 = v27 + __ROL4__(x[5] + (v27 & v25 | v26 & ~v25) - 701558691 + v24, 5);
  v29 = v28 + __ROL4__(x[10] + (v28 & v26 | v27 & ~v26) + 38016083 + v25, 9);
  v30 = v29 + __ROL4__(x[15] + (v27 & v29 | v28 & ~v27) - 660478335 + v26, 14);
  v31 = v30 + __ROR4__(x[4] + (v28 & v30 | v29 & ~v28) - 405537848 + v27, 12);
  v32 = v31 + __ROL4__(x[9] + (v31 & v29 | v30 & ~v29) + 568446438 + v28, 5);
  v33 = v32 + __ROL4__(v29 + x[14] + (v32 & v30 | v31 & ~v30) - 1019803690, 9);
  v34 = v33 + __ROL4__(x[3] + (v31 & v33 | v32 & ~v31) - 187363961 + v30, 14);
  v35 = __ROR4__(x[8] + (v32 & v34 | v33 & ~v32) + 1163531501 + v31, 12);
  v74 = v34 + v35;
  v36 = v34 + v35 + __ROL4__(x[13] + ((v34 + v35) & v33 | v34 & ~v33) + v32 - 1444681467, 5);
  v37 = v36 + __ROL4__(x[2] + (v36 & v34 | (v34 + v35) & ~v34) + v33 - 51403784, 9);
  v38 = v37 + __ROL4__(x[7] + ((v34 + v35) & v37 | v36 & ~(v34 + v35)) + v34 + 1735328473, 14);
  v39 = v38 + __ROR4__(x[12] + (v36 & v38 | v37 & ~v36) + v74 - 1926607734, 12);
  v40 = v39 + __ROL4__(x[5] + (v39 ^ v38 ^ v37) - 378558 + v36, 4);
  v41 = v40 + __ROL4__(x[8] + (v40 ^ v39 ^ v38) - 2022574463 + v37, 11);
  v42 = v41 + __ROL4__(x[11] + (v40 ^ v39 ^ v41) + 1839030562 + v38, 16);
  v43 = v42 + __ROR4__(x[14] + (v40 ^ v42 ^ v41) - 35309556 + v39, 9);
  v44 = v43 + __ROL4__(x[1] + (v43 ^ v42 ^ v41) - 1530992060 + v40, 4);
  v45 = v44 + __ROL4__(x[4] + (v44 ^ v43 ^ v42) + 1272893353 + v41, 11);
  v46 = v45 + __ROL4__(x[7] - 155497632 + (v44 ^ v43 ^ v45) + v42, 16);
  v47 = v46 + __ROR4__(x[10] + (v44 ^ v46 ^ v45) - 1094730640 + v43, 9);
  v48 = v47 + __ROL4__(x[13] + (v47 ^ v46 ^ v45) + v44 + 681279174, 4);
  v49 = v48 + __ROL4__(x[0] + (v48 ^ v47 ^ v46) - 358537222 + v45, 11);
  v50 = v49 + __ROL4__(x[3] + (v48 ^ v47 ^ v49) - 722521979 + v46, 16);
  v51 = v50 + __ROR4__(v47 + x[6] + (v48 ^ v50 ^ v49) + 76029189, 9);
  v52 = v51 + __ROL4__(v48 + x[9] + (v51 ^ v50 ^ v49) - 640364487, 4);
  v53 = v52 + __ROL4__(x[12] + (v52 ^ v51 ^ v50) - 421815835 + v49, 11);
  v54 = v53 + __ROL4__(x[15] + (v52 ^ v51 ^ v53) + 530742520 + v50, 16);
  v55 = v54 + __ROR4__(x[2] + (v52 ^ v54 ^ v53) - 995338651 + v51, 9);
  v56 = v55 + __ROL4__(x[0] + (v54 ^ (v55 | ~v53)) - 198630844 + v52, 6);
  v57 = v56 + __ROL4__(x[7] + (v55 ^ (v56 | ~v54)) + 1126891415 + v53, 10);
  v58 = v57 + __ROL4__(x[14] + (v56 ^ (v57 | ~v55)) - 1416354905 + v54, 15);
  v59 = v58 + __ROR4__(x[5] + (v57 ^ (v58 | ~v56)) - 57434055 + v55, 11);
  v60 = v59 + __ROL4__(x[12] + (v58 ^ (v59 | ~v57)) + 1700485571 + v56, 6);
  v61 = v60 + __ROL4__(x[3] + (v59 ^ (v60 | ~v58)) - 1894986606 + v57, 10);
  v62 = v61 + __ROL4__(x[10] + (v60 ^ (v61 | ~v59)) - 1051523 + v58, 15);
  v63 = v62 + __ROR4__(x[1] + (v61 ^ (v62 | ~v60)) - 2054922799 + v59, 11);
  v64 = v63 + __ROL4__(x[8] + (v62 ^ (v63 | ~v61)) + 1873313359 + v60, 6);
  v65 = v64 + __ROL4__(x[15] + (v63 ^ (v64 | ~v62)) + v61 - 30611744, 10);
  v66 = v65 + __ROL4__(x[6] + (v64 ^ (v65 | ~v63)) - 1560198380 + v62, 15);
  v67 = v66 + __ROR4__(x[13] + (v65 ^ (v66 | ~v64)) + v63 + 1309151649, 11);
  v68 = v67 + __ROL4__(x[4] + (v66 ^ (v67 | ~v65)) + v64 - 145523070, 6);
  v69 = v68 + __ROL4__(x[11] + (v67 ^ (v68 | ~v66)) + v65 - 1120210379, 10);
  this->state[3] += v69;
  v70 = v69 + __ROL4__(x[2] + (v68 ^ (v69 | ~v67)) + v66 + 718787259, 15);
  this->state[0] = v68 + v75;
  this->state[2] += v70;
  this->state[1] += v70 + __ROR4__(x[9] + (v69 ^ (v70 | ~v68)) + v67 - 343485551, 11);
}
void MD5CheckSum::update(MD5CheckSum *this, const unsigned __int8 *buf, unsigned int size)
{
  unsigned int v4; // eax
  int v5; // ecx
  unsigned int v6; // edx
  int v7; // edi
  unsigned int i; // esi

  v4 = this->count[0];
  v5 = (v4 >> 3) & 0x3F;
  v6 = v4 + 8 * size;
  this->count[0] = v6;
  if ( v6 < 8 * size )
    ++this->count[1];
  v7 = 64 - v5;
  this->count[1] += size >> 29;
  if ( size < 64 - v5 )
  {
    v7 = 0;
  }
  else
  {
    memcpy(&this->buffer[v5], buf, 64 - v5);
    MD5CheckSum::transform(this, this->buffer);
    for ( i = v7 + 64; i <= size; v7 += 64 )
    {
      MD5CheckSum::transform(this, &buf[i - 64]);
      i += 64;
    }
    v5 = 0;
  }
  memcpy(&this->buffer[v5], &buf[v7], size - v7);
}
