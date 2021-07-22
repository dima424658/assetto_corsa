#include "sessionresultprocessor.h"
void SessionResultProcessor::fetchBasicResults(SessionResultProcessor *this)
{
  SessionResultProcessor *v1; // edi
  int *v2; // ecx
  int v3; // edx
  unsigned int v4; // esi
  Sim *v5; // ecx
  unsigned int i; // ebp
  CarAvatar *v7; // eax
  std::vector<Lap> *v8; // esi
  std::vector<Lap> *v9; // ebx
  int v10; // edi
  unsigned int v11; // edi
  LeaderboardEntry *v12; // ecx
  int v13; // ebx
  unsigned int v14; // eax
  int *v15; // esi
  std::vector<Lap> laps; // [esp+24h] [ebp-24h] BYREF
  std::vector<LeaderboardEntry> lb; // [esp+30h] [ebp-18h] BYREF
  int v19; // [esp+44h] [ebp-4h]

  v1 = this;
  std::_Container_base0::_Orphan_all((std::_Container_base0 *)&res);
  std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::vector<Lap>>>>(res.laps._Myfirst, res.laps._Mylast);
  res.laps._Mylast = res.laps._Myfirst;
  std::_Container_base0::_Orphan_all(&res.positions);
  res.positions._Mylast = res.positions._Myfirst;
  std::vector<float>::resize((std::vector<float> *)&res.positions, v1->sim->cars._Mylast - v1->sim->cars._Myfirst);
  v2 = res.positions._Myfirst;
  v3 = 0;
  v4 = (unsigned int)((char *)res.positions._Mylast - (char *)res.positions._Myfirst + 3) >> 2;
  if ( res.positions._Myfirst > res.positions._Mylast )
    v4 = 0;
  if ( v4 )
  {
    do
    {
      ++v3;
      *v2++ = -1;
    }
    while ( v3 != v4 );
  }
  v5 = v1->sim;
  for ( i = 0; i < v1->sim->cars._Mylast - v1->sim->cars._Myfirst; ++i )
  {
    v7 = Sim::getCar(v5, i);
    RaceManager::getLaps(v1->sim->raceManager, &laps, v7, 1);
    v8 = res.laps._Mylast;
    v19 = 0;
    if ( &laps >= res.laps._Mylast || (v9 = res.laps._Myfirst, res.laps._Myfirst > &laps) )
    {
      if ( res.laps._Mylast == res.laps._Myend )
      {
        std::vector<std::vector<Lap>>::_Reserve(&res.laps, 1u);
        v8 = res.laps._Mylast;
      }
      LOBYTE(v19) = 2;
      if ( v8 )
      {
        std::vector<Lap>::vector<Lap>(v8, &laps);
        v8 = res.laps._Mylast;
      }
    }
    else
    {
      v10 = &laps - res.laps._Myfirst;
      if ( res.laps._Mylast == res.laps._Myend )
      {
        std::vector<std::vector<Lap>>::_Reserve(&res.laps, 1u);
        v8 = res.laps._Mylast;
        v9 = res.laps._Myfirst;
      }
      LOBYTE(v19) = 1;
      if ( v8 )
      {
        std::vector<Lap>::vector<Lap>(v8, &v9[v10]);
        v8 = res.laps._Mylast;
      }
      v1 = this;
    }
    v19 = -1;
    res.laps._Mylast = v8 + 1;
    if ( laps._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&laps);
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(laps._Myfirst, laps._Mylast);
      operator delete(laps._Myfirst);
      laps._Myfirst = 0;
      laps._Mylast = 0;
      laps._Myend = 0;
    }
    v5 = v1->sim;
  }
  RaceManager::getLeaderboard(v1->sim->raceManager, &lb);
  v11 = 0;
  v12 = lb._Myfirst;
  v19 = 3;
  if ( lb._Mylast - lb._Myfirst )
  {
    v13 = 0;
    do
    {
      v14 = CarAvatar::getGuid(v12[v13].car);
      if ( RaceManager::isRaceOver(this->sim->raceManager, v14) )
      {
        v15 = &res.positions._Myfirst[v11];
        *v15 = CarAvatar::getGuid(lb._Myfirst[v13].car);
      }
      else
      {
        res.positions._Myfirst[v11] = -1;
      }
      ++v11;
      v12 = lb._Myfirst;
      ++v13;
    }
    while ( v11 < lb._Mylast - lb._Myfirst );
  }
  v19 = -1;
  if ( v12 )
  {
    std::_Container_base0::_Orphan_all(&lb);
    operator delete(lb._Myfirst);
  }
}
SessionResult *SessionResultProcessor::getCompleteAIResults(SessionResultProcessor *this, SessionResult *result)
{
  switch ( RaceManager::getCurrentSessionType(this->sim->raceManager) )
  {
    case Pratice:
    case Qualify:
      SessionResultProcessor::processQualifyResults(this);
      break;
    case Race:
      SessionResultProcessor::processRaceResults(this);
      break;
    case Drag:
      SessionResultProcessor::processDragResults(this);
      break;
    default:
      SessionResultProcessor::fetchBasicResults(this);
      break;
  }
  std::vector<std::vector<Lap>>::vector<std::vector<Lap>>(&result->laps, &res.laps);
  std::vector<Lap>::vector<Lap>(&result->bestLaps, &res.bestLaps);
  std::vector<Mesh *>::vector<Mesh *>(
    (std::vector<TyreThermalPatch *> *)&result->positions,
    (const std::vector<TyreThermalPatch *> *)&res.positions);
  std::vector<Mesh *>::vector<Mesh *>(
    (std::vector<TyreThermalPatch *> *)&result->lapCount,
    (const std::vector<TyreThermalPatch *> *)&res.lapCount);
  std::vector<unsigned int>::vector<unsigned int>(
    (std::vector<unsigned int> *)&result->total,
    (const std::vector<unsigned int> *)&res.total);
  return result;
}
void SessionResultProcessor::processDragResults(SessionResultProcessor *this)
{
  Sim *v2; // ebx
  GameObject **v3; // esi
  int v4; // edi
  Sim *v5; // ecx
  unsigned int v6; // esi
  std::map<CarAvatar *,std::vector<Lap>> *v7; // edi
  CarAvatar *const *v8; // eax
  int v9; // eax
  CarAvatar *_Keyval; // [esp+18h] [ebp-20h] BYREF
  int v11; // [esp+1Ch] [ebp-1Ch]
  std::vector<Lap> laps; // [esp+20h] [ebp-18h] BYREF
  int v13; // [esp+34h] [ebp-4h]

  v2 = this->sim;
  v3 = this->sim->gameObjects._Myfirst;
  if ( v3 != this->sim->gameObjects._Mylast )
  {
    while ( 1 )
    {
      v4 = __RTDynamicCast(*v3, 0, &GameObject `RTTI Type Descriptor', &DragMode `RTTI Type Descriptor', 0);
      v11 = v4;
      if ( v4 )
        break;
      if ( ++v3 == v2->gameObjects._Mylast )
        return;
    }
    std::vector<float>::resize((std::vector<float> *)&res.positions, 2u);
    v5 = this->sim;
    v6 = 0;
    if ( this->sim->cars._Mylast - this->sim->cars._Myfirst )
    {
      _Keyval = (CarAvatar *)(v4 + 120);
      v7 = (std::map<CarAvatar *,std::vector<Lap>> *)(v4 + 120);
      do
      {
        _Keyval = Sim::getCar(v5, v6);
        v8 = std::map<CarAvatar *,std::vector<Lap>>::operator[](v7, &_Keyval);
        std::vector<Lap>::vector<Lap>(&laps, (const std::vector<Lap> *)v8);
        v13 = 0;
        std::vector<std::vector<Lap>>::push_back(&res.laps, &laps);
        v13 = -1;
        if ( laps._Myfirst )
        {
          std::_Container_base0::_Orphan_all(&laps);
          std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(laps._Myfirst, laps._Mylast);
          operator delete(laps._Myfirst);
          laps._Myfirst = 0;
          laps._Mylast = 0;
          laps._Myend = 0;
        }
        v5 = this->sim;
        ++v6;
      }
      while ( v6 < this->sim->cars._Mylast - this->sim->cars._Myfirst );
      v4 = v11;
    }
    if ( ((*(_DWORD *)(v4 + 132) - *(_DWORD *)(v4 + 128)) & 0xFFFFFFC0) != 0 )
      v9 = *(_DWORD *)(*(_DWORD *)(v4 + 128) + 4);
    else
      v9 = 0;
    if ( (float)v9 <= (float)((float)((float)*(int *)(v4 + 156) + 0.5) * 0.5) )
    {
      res.positions._Myfirst[1] = 0;
      *res.positions._Myfirst = 1;
    }
    else
    {
      *res.positions._Myfirst = 0;
      res.positions._Myfirst[1] = 1;
    }
  }
}
void SessionResultProcessor::processQualifyResults(SessionResultProcessor *this)
{
  SessionResultProcessor *v1; // ebx
  Sim *v2; // ecx
  Sim *v3; // edx
  unsigned int v4; // ecx
  BestLap *v5; // edi
  BestLap *v6; // esi
  CarAvatar *v7; // eax
  CarAvatar *v8; // eax
  Lap *v9; // edi
  BestLap *v10; // esi
  BestLap *v11; // eax
  unsigned int v12; // ecx
  BestLap *v13; // ecx
  bool v14; // al
  const std::wstring *v15; // edi
  std::wstring *v16; // ecx
  CarAvatar *v17; // eax
  std::vector<Lap> *v18; // edi
  std::vector<Lap> *v19; // esi
  unsigned int v20; // edx
  Sim *v21; // ecx
  unsigned int v22; // edi
  CarAvatar *v23; // eax
  CarAvatar *v24; // eax
  Lap *v25; // eax
  CarAvatar *v26; // eax
  Lap *v27; // esi
  bool v28; // al
  const std::wstring *v29; // esi
  long double v30; // st7
  BestLap *v31; // esi
  std::vector<unsigned int> *v32; // edi
  int v33; // eax
  const wchar_t *v34; // ecx
  Sim *v35; // ecx
  unsigned int i; // ebx
  int v37; // edi
  CarAvatar *v38; // eax
  unsigned int v39; // ecx
  CarAvatar *v40; // eax
  CarAvatar *v41; // eax
  Lap *v42; // eax
  CarAvatar *v43; // eax
  Lap *v44; // edi
  bool v45; // al
  const std::wstring *v46; // edi
  char v47; // al
  const std::wstring *v48; // edi
  unsigned int v49; // edi
  int v50; // eax
  unsigned int *v51; // ecx
  unsigned int v52; // ebx
  unsigned int *v53; // eax
  int v54; // edx
  unsigned int v55; // eax
  int v56; // ebx
  int v57; // ebx
  std::vector<Lap> *v58; // ecx
  std::vector<Lap> *v59; // esi
  std::vector<Lap> *v60; // edi
  int v61; // esi
  int *v62; // esi
  int *v63; // ecx
  int v64; // edi
  int v65; // edi
  int v66; // ecx
  unsigned int v67; // edx
  unsigned int v68; // edx
  int v69; // ecx
  unsigned int v70; // edx
  unsigned int v71; // edx
  BestLap *v72; // ecx
  unsigned int v73; // ebx
  int v74; // edx
  int v75; // eax
  int *v76; // ecx
  int *v77; // esi
  int v78; // edi
  int v79; // ecx
  unsigned int v80; // edx
  unsigned int v81; // edx
  int v82; // ecx
  unsigned int v83; // edx
  unsigned int v84; // edx
  unsigned int v85; // [esp-4h] [ebp-110h]
  bool v86; // [esp+13h] [ebp-F9h]
  bool v87; // [esp+13h] [ebp-F9h]
  unsigned int v89; // [esp+14h] [ebp-F8h]
  int v90; // [esp+14h] [ebp-F8h]
  char _Count_3; // [esp+1Bh] [ebp-F1h]
  unsigned int _Count_4; // [esp+1Ch] [ebp-F0h]
  unsigned int _Count_4a; // [esp+1Ch] [ebp-F0h]
  std::vector<BestLap> bestLaps; // [esp+24h] [ebp-E8h] BYREF
  BestLap *index; // [esp+30h] [ebp-DCh]
  long double index_4; // [esp+34h] [ebp-D8h]
  int v97; // [esp+40h] [ebp-CCh] BYREF
  int v98; // [esp+44h] [ebp-C8h] BYREF
  std::vector<Lap> result; // [esp+48h] [ebp-C4h] BYREF
  BestLap defaultBestLap; // [esp+54h] [ebp-B8h] BYREF
  Lap newLap; // [esp+98h] [ebp-74h] BYREF
  Lap v102; // [esp+C8h] [ebp-44h] BYREF
  int v103; // [esp+108h] [ebp-4h]

  v1 = this;
  std::_Container_base0::_Orphan_all((std::_Container_base0 *)&res);
  std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::vector<Lap>>>>(res.laps._Myfirst, res.laps._Mylast);
  res.laps._Mylast = res.laps._Myfirst;
  std::_Container_base0::_Orphan_all(&res.positions);
  res.positions._Mylast = res.positions._Myfirst;
  std::_Container_base0::_Orphan_all(&res.lapCount);
  res.lapCount._Mylast = res.lapCount._Myfirst;
  std::_Container_base0::_Orphan_all(&res.bestLaps);
  std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(res.bestLaps._Myfirst, res.bestLaps._Mylast);
  res.bestLaps._Mylast = res.bestLaps._Myfirst;
  bestLaps._Myfirst = 0;
  bestLaps._Mylast = 0;
  bestLaps._Myend = 0;
  v2 = v1->sim;
  v103 = 0;
  std::vector<BestLap>::resize(&bestLaps, v2->cars._Mylast - v2->cars._Myfirst);
  v3 = v1->sim;
  v4 = 0;
  _Count_4 = 0x7FFFFFFF;
  LODWORD(index_4) = 0;
  if ( v3->cars._Mylast - v3->cars._Myfirst )
  {
    v5 = 0;
    index = 0;
    do
    {
      v6 = bestLaps._Myfirst;
      v7 = Sim::getCar(v3, v4);
      v85 = LODWORD(index_4);
      *(CarAvatar **)((char *)&v5->car + (_DWORD)v6) = v7;
      v8 = Sim::getCar(v1->sim, v85);
      v9 = RaceManager::getBestLap(v1->sim->raceManager, &newLap, v8);
      v10 = bestLaps._Myfirst;
      v11 = index;
      v12 = v9->time;
      LOBYTE(v103) = 1;
      *(unsigned int *)((char *)&bestLaps._Myfirst->bestLap.time + (unsigned int)index) = v12;
      std::vector<int>::operator=(
        (std::vector<unsigned int> *)((char *)&v11->bestLap.splits + (_DWORD)v10),
        &v9->splits);
      v13 = index;
      *(unsigned int *)((char *)&index->bestLap.cuts + (_DWORD)v10) = v9->cuts;
      v14 = v9->isValid;
      v15 = &v9->compound;
      *(&v13->bestLap.isValid + (_DWORD)v10) = v14;
      v16 = (std::wstring *)((char *)&v13->bestLap.compound + (_DWORD)v10);
      if ( v16 != v15 )
        std::wstring::assign(v16, v15, 0, 0xFFFFFFFF);
      LOBYTE(v103) = 0;
      if ( newLap.compound._Myres >= 8 )
        operator delete(newLap.compound._Bx._Ptr);
      newLap.compound._Myres = 7;
      newLap.compound._Mysize = 0;
      newLap.compound._Bx._Buf[0] = 0;
      if ( newLap.splits._Myfirst )
      {
        std::_Container_base0::_Orphan_all(&newLap.splits);
        operator delete(newLap.splits._Myfirst);
      }
      v17 = Sim::getCar(v1->sim, LODWORD(index_4));
      v18 = RaceManager::getLaps(v1->sim->raceManager, &result, v17, 1);
      LOBYTE(v103) = 2;
      v19 = (std::vector<Lap> *)((char *)bestLaps._Myfirst + (unsigned int)&index->laps);
      if ( v19 != v18 )
      {
        if ( v19->_Myfirst )
        {
          std::_Container_base0::_Orphan_all((std::_Container_base0 *)bestLaps._Myfirst + (unsigned int)&index->laps);
          std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(v19->_Myfirst, v19->_Mylast);
          operator delete(v19->_Myfirst);
          v19->_Myfirst = 0;
          v19->_Mylast = 0;
          v19->_Myend = 0;
        }
        std::_Container_base0::_Swap_all(v19, v18);
        v19->_Myfirst = v18->_Myfirst;
        v19->_Mylast = v18->_Mylast;
        v19->_Myend = v18->_Myend;
        v18->_Myfirst = 0;
        v18->_Mylast = 0;
        v18->_Myend = 0;
      }
      LOBYTE(v103) = 0;
      if ( result._Myfirst )
      {
        std::_Container_base0::_Orphan_all(&result);
        std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(result._Myfirst, result._Mylast);
        operator delete(result._Myfirst);
        result._Myfirst = 0;
        result._Mylast = 0;
        result._Myend = 0;
      }
      v20 = _Count_4;
      if ( *(unsigned int *)((char *)&bestLaps._Myfirst->bestLap.time + (unsigned int)index) < _Count_4 )
        v20 = *(unsigned int *)((char *)&bestLaps._Myfirst->bestLap.time + (unsigned int)index);
      v4 = LODWORD(index_4) + 1;
      _Count_4 = v20;
      v5 = index + 1;
      v3 = v1->sim;
      LODWORD(index_4) = v4;
      ++index;
    }
    while ( v4 < v3->cars._Mylast - v3->cars._Myfirst );
  }
  defaultBestLap.bestLap.splits._Myfirst = 0;
  defaultBestLap.bestLap.splits._Mylast = 0;
  defaultBestLap.bestLap.splits._Myend = 0;
  defaultBestLap.bestLap.compound._Myres = 7;
  defaultBestLap.bestLap.compound._Mysize = 0;
  defaultBestLap.bestLap.compound._Bx._Buf[0] = 0;
  defaultBestLap.bestLap.isValid = 0;
  defaultBestLap.bestLap.cuts = 0;
  defaultBestLap.laps._Myfirst = 0;
  defaultBestLap.laps._Mylast = 0;
  defaultBestLap.laps._Myend = 0;
  v21 = v1->sim;
  v22 = 0;
  _Count_3 = 0;
  defaultBestLap.bestLap.time = 0x7FFFFFFF;
  LOBYTE(v103) = 3;
  if ( v21->cars._Mylast - v21->cars._Myfirst )
  {
    do
    {
      v23 = Sim::getCar(v21, v22);
      if ( RaceManager::getLapCount(v1->sim->raceManager, v23) )
      {
        v24 = Sim::getCar(v1->sim, v22);
        v25 = RaceManager::getBestLap(v1->sim->raceManager, &newLap, v24);
        v86 = defaultBestLap.bestLap.time > v25->time;
        if ( newLap.compound._Myres >= 8 )
          operator delete(newLap.compound._Bx._Ptr);
        newLap.compound._Myres = 7;
        newLap.compound._Mysize = 0;
        newLap.compound._Bx._Buf[0] = 0;
        if ( newLap.splits._Myfirst )
        {
          std::_Container_base0::_Orphan_all(&newLap.splits);
          operator delete(newLap.splits._Myfirst);
        }
        if ( v86 )
        {
          v26 = Sim::getCar(v1->sim, v22);
          v27 = RaceManager::getBestLap(v1->sim->raceManager, &newLap, v26);
          defaultBestLap.bestLap.time = v27->time;
          LOBYTE(v103) = 4;
          std::vector<int>::operator=(&defaultBestLap.bestLap.splits, &v27->splits);
          defaultBestLap.bestLap.cuts = v27->cuts;
          v28 = v27->isValid;
          v29 = &v27->compound;
          defaultBestLap.bestLap.isValid = v28;
          if ( &defaultBestLap.bestLap.compound != v29 )
            std::wstring::assign(&defaultBestLap.bestLap.compound, v29, 0, 0xFFFFFFFF);
          LOBYTE(v103) = 3;
          if ( newLap.compound._Myres >= 8 )
            operator delete(newLap.compound._Bx._Ptr);
          newLap.compound._Myres = 7;
          newLap.compound._Mysize = 0;
          newLap.compound._Bx._Buf[0] = 0;
          if ( newLap.splits._Myfirst )
          {
            std::_Container_base0::_Orphan_all(&newLap.splits);
            operator delete(newLap.splits._Myfirst);
          }
          defaultBestLap.car = Sim::getCar(v1->sim, v22);
          _Count_3 = 1;
        }
      }
      v21 = v1->sim;
      ++v22;
    }
    while ( v22 < v1->sim->cars._Mylast - v1->sim->cars._Myfirst );
  }
  v30 = RaceManager::getSessionTimeLeft(v1->sim->raceManager);
  v31 = bestLaps._Mylast;
  index_4 = v30;
  if ( (int)v30 > (int)_Count_4 )
  {
    index = bestLaps._Mylast;
    if ( bestLaps._Myfirst != bestLaps._Mylast )
    {
      v32 = &bestLaps._Myfirst->bestLap.splits;
      LODWORD(index_4) = &bestLaps._Myfirst->bestLap.splits;
      do
      {
        if ( CarAvatar::getGuid((CarAvatar *)v32[-1]._Mylast) )
        {
          v33 = ((char *)v32[4]._Myfirst - (char *)v32[3]._Myend) / 48 ? (int)(RaceManager::getSessionTimeLeft(v1->sim->raceManager)
                                                                             / (double)(unsigned int)v32[-1]._Myend) : 1;
          _Count_4a = v33;
          if ( v33 > 0 )
          {
            do
            {
              newLap.splits._Myfirst = 0;
              newLap.splits._Mylast = 0;
              newLap.splits._Myend = 0;
              newLap.compound._Myres = 7;
              newLap.compound._Mysize = 0;
              newLap.compound._Bx._Buf[0] = 0;
              newLap.isValid = 0;
              newLap.cuts = 0;
              newLap.time = defaultBestLap.bestLap.time;
              LOBYTE(v103) = 5;
              std::vector<int>::operator=(&newLap.splits, &defaultBestLap.bestLap.splits);
              newLap.cuts = defaultBestLap.bestLap.cuts;
              newLap.isValid = defaultBestLap.bestLap.isValid;
              std::wstring::assign(&newLap.compound, &defaultBestLap.bestLap.compound, 0, 0xFFFFFFFF);
              if ( _Count_3 )
              {
                v34 = (const wchar_t *)(v32[-1]._Mylast + 56);
                if ( v32[-1]._Mylast[61] >= 8 )
                  v34 = *(const wchar_t **)v34;
                if ( std::wstring::compare(
                       &defaultBestLap.car->guiName,
                       0,
                       defaultBestLap.car->guiName._Mysize,
                       v34,
                       v32[-1]._Mylast[60]) )
                {
                  v35 = this->sim;
                  for ( i = 0;
                        i < this->sim->cars._Mylast - this->sim->cars._Myfirst;
                        v32 = (std::vector<unsigned int> *)LODWORD(index_4) )
                  {
                    v37 = (int)(v32[-1]._Mylast + 56);
                    v38 = Sim::getCar(v35, i);
                    v39 = *(_DWORD *)(v37 + 16);
                    if ( *(_DWORD *)(v37 + 20) >= 8u )
                      v37 = *(_DWORD *)v37;
                    if ( !std::wstring::compare(&v38->guiName, 0, v38->guiName._Mysize, (const wchar_t *)v37, v39) )
                    {
                      v40 = Sim::getCar(this->sim, i);
                      if ( RaceManager::getLapCount(this->sim->raceManager, v40) )
                      {
                        v41 = Sim::getCar(this->sim, i);
                        v42 = RaceManager::getBestLap(this->sim->raceManager, &v102, v41);
                        v87 = newLap.time > v42->time;
                        if ( v102.compound._Myres >= 8 )
                          operator delete(v102.compound._Bx._Ptr);
                        v102.compound._Myres = 7;
                        v102.compound._Mysize = 0;
                        v102.compound._Bx._Buf[0] = 0;
                        if ( v102.splits._Myfirst )
                        {
                          std::_Container_base0::_Orphan_all(&v102.splits);
                          operator delete(v102.splits._Myfirst);
                        }
                        if ( v87 )
                        {
                          v43 = Sim::getCar(this->sim, i);
                          v44 = RaceManager::getBestLap(this->sim->raceManager, &v102, v43);
                          newLap.time = v44->time;
                          LOBYTE(v103) = 6;
                          std::vector<int>::operator=(&newLap.splits, &v44->splits);
                          newLap.cuts = v44->cuts;
                          v45 = v44->isValid;
                          v46 = &v44->compound;
                          newLap.isValid = v45;
                          if ( &newLap.compound != v46 )
                            std::wstring::assign(&newLap.compound, v46, 0, 0xFFFFFFFF);
                          LOBYTE(v103) = 5;
                          if ( v102.compound._Myres >= 8 )
                            operator delete(v102.compound._Bx._Ptr);
                          v102.compound._Myres = 7;
                          v102.compound._Mysize = 0;
                          v102.compound._Bx._Buf[0] = 0;
                          if ( v102.splits._Myfirst )
                          {
                            std::_Container_base0::_Orphan_all(&v102.splits);
                            operator delete(v102.splits._Myfirst);
                          }
                        }
                      }
                    }
                    v35 = this->sim;
                    ++i;
                  }
                }
              }
              else
              {
                newLap.time = 600000;
              }
              if ( (unsigned int)RaceManager::getLapCount(this->sim->raceManager, (CarAvatar *)v32[-1]._Mylast) > 1 )
              {
                newLap.time = (unsigned int)v32[-1]._Myend;
                std::vector<int>::operator=(&newLap.splits, v32);
                newLap.cuts = (unsigned int)v32[1]._Myfirst;
                v47 = (char)v32[1]._Mylast;
                v48 = (const std::wstring *)&v32[1]._Myend;
                newLap.isValid = v47;
                if ( &newLap.compound != v48 )
                  std::wstring::assign(&newLap.compound, v48, 0, 0xFFFFFFFF);
              }
              v49 = newLap.time;
              v50 = _rand();
              v51 = newLap.splits._Mylast;
              v52 = (int)(float)((float)((float)((float)v50 * 0.000030518509) - 0.69999999) * 100.0) + newLap.time;
              v53 = newLap.splits._Myfirst;
              newLap.time = v52;
              v54 = (int)(float)((float)(int)(v49 - v52)
                               / (float)((double)(newLap.splits._Mylast - newLap.splits._Myfirst)
                                       + _xmm[(unsigned int)((char *)newLap.splits._Mylast
                                                           - (char *)newLap.splits._Myfirst) >> 31]));
              if ( newLap.splits._Myfirst != newLap.splits._Mylast )
              {
                do
                  *v53++ -= v54;
                while ( v53 != v51 );
                v52 = newLap.time;
              }
              v32 = (std::vector<unsigned int> *)LODWORD(index_4);
              v55 = *(_DWORD *)(LODWORD(index_4) - 4);
              if ( !v55 || v52 < v55 )
              {
                *(_DWORD *)(LODWORD(index_4) - 4) = v52;
                std::vector<int>::operator=(v32, &newLap.splits);
                v32[1]._Myfirst = (unsigned int *)newLap.cuts;
                LOBYTE(v32[1]._Mylast) = newLap.isValid;
                if ( &v32[1]._Myend != (unsigned int **)&newLap.compound )
                  std::wstring::assign((std::wstring *)&v32[1]._Myend, &newLap.compound, 0, 0xFFFFFFFF);
              }
              std::vector<Lap>::push_back((std::vector<Lap> *)&v32[3]._Myend, &newLap);
              v56 = _Count_4a - 1;
              LOBYTE(v103) = 3;
              --_Count_4a;
              if ( newLap.compound._Myres >= 8 )
                operator delete(newLap.compound._Bx._Ptr);
              newLap.compound._Myres = 7;
              newLap.compound._Mysize = 0;
              newLap.compound._Bx._Buf[0] = 0;
              if ( newLap.splits._Myfirst )
              {
                std::_Container_base0::_Orphan_all(&newLap.splits);
                operator delete(newLap.splits._Myfirst);
              }
            }
            while ( v56 > 0 );
            v31 = index;
            v1 = this;
          }
        }
        v32 = (std::vector<unsigned int> *)((char *)v32 + 64);
        LODWORD(index_4) = v32;
      }
      while ( &v32[-1]._Mylast != (unsigned int **)v31 );
      v31 = bestLaps._Mylast;
    }
  }
  v89 = 0;
  if ( v31 - bestLaps._Myfirst )
  {
    v57 = 0;
    do
    {
      std::vector<Lap>::push_back(&res.bestLaps, &bestLaps._Myfirst[v57].bestLap);
      v58 = res.laps._Mylast;
      v59 = &bestLaps._Myfirst[v57].laps;
      if ( v59 >= res.laps._Mylast || (v60 = res.laps._Myfirst, res.laps._Myfirst > v59) )
      {
        if ( res.laps._Mylast == res.laps._Myend )
        {
          std::vector<std::vector<Lap>>::_Reserve(&res.laps, 1u);
          v58 = res.laps._Mylast;
        }
        LODWORD(index_4) = v58;
        LOBYTE(v103) = 8;
        if ( v58 )
        {
          std::vector<Lap>::vector<Lap>(v58, v59);
          goto LABEL_94;
        }
      }
      else
      {
        v61 = v59 - res.laps._Myfirst;
        if ( res.laps._Mylast == res.laps._Myend )
        {
          std::vector<std::vector<Lap>>::_Reserve(&res.laps, 1u);
          v58 = res.laps._Mylast;
          v60 = res.laps._Myfirst;
        }
        LODWORD(index_4) = v58;
        LOBYTE(v103) = 7;
        if ( v58 )
        {
          std::vector<Lap>::vector<Lap>(v58, &v60[v61]);
LABEL_94:
          v58 = res.laps._Mylast;
          goto LABEL_95;
        }
      }
LABEL_95:
      v62 = res.lapCount._Myfirst;
      res.laps._Mylast = v58 + 1;
      LOBYTE(v103) = 3;
      v63 = res.lapCount._Mylast;
      v64 = bestLaps._Myfirst[v57].laps._Mylast - bestLaps._Myfirst[v57].laps._Myfirst;
      v98 = v64;
      if ( &v98 >= res.lapCount._Mylast || res.lapCount._Myfirst > &v98 )
      {
        if ( res.lapCount._Mylast == res.lapCount._Myend && !(res.lapCount._Myend - res.lapCount._Mylast) )
        {
          v69 = res.lapCount._Mylast - res.lapCount._Myfirst;
          if ( v69 == 0x3FFFFFFF )
LABEL_130:
            std::_Xlength_error("vector<T> too long");
          v70 = res.lapCount._Myend - res.lapCount._Myfirst;
          if ( 0x3FFFFFFF - (v70 >> 1) >= v70 )
            v71 = (v70 >> 1) + v70;
          else
            v71 = 0;
          if ( v71 < v69 + 1 )
            v71 = v69 + 1;
          std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)&res.lapCount, v71);
          v63 = res.lapCount._Mylast;
        }
        if ( !v63 )
          goto LABEL_120;
        *v63 = v64;
      }
      else
      {
        v65 = &v98 - res.lapCount._Myfirst;
        if ( res.lapCount._Mylast == res.lapCount._Myend && !(res.lapCount._Myend - res.lapCount._Mylast) )
        {
          v66 = res.lapCount._Mylast - res.lapCount._Myfirst;
          if ( v66 == 0x3FFFFFFF )
            goto LABEL_130;
          v67 = res.lapCount._Myend - res.lapCount._Myfirst;
          if ( 0x3FFFFFFF - (v67 >> 1) >= v67 )
            v68 = (v67 >> 1) + v67;
          else
            v68 = 0;
          if ( v68 < v66 + 1 )
            v68 = v66 + 1;
          std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)&res.lapCount, v68);
          v63 = res.lapCount._Mylast;
          v62 = res.lapCount._Myfirst;
        }
        if ( !v63 )
          goto LABEL_120;
        *v63 = v62[v65];
      }
      v63 = res.lapCount._Mylast;
LABEL_120:
      v31 = bestLaps._Mylast;
      ++v57;
      res.lapCount._Mylast = v63 + 1;
      ++v89;
    }
    while ( v89 < bestLaps._Mylast - bestLaps._Myfirst );
  }
  std::_Sort<BestLap *,int,_lambda_b629da58478cbfbbaf49a3b3054e0e7d_>(
    bestLaps._Myfirst,
    v31,
    v31 - bestLaps._Myfirst,
    (SessionResultProcessor::processQualifyResults::__l67::<lambda_b629da58478cbfbbaf49a3b3054e0e7d>)v89);
  v72 = bestLaps._Myfirst;
  v73 = 0;
  if ( bestLaps._Mylast - bestLaps._Myfirst )
  {
    v74 = 0;
    v90 = 0;
    do
    {
      v75 = CarAvatar::getGuid(*(CarAvatar **)((char *)&v72->car + v74));
      v76 = res.positions._Mylast;
      v77 = res.positions._Myfirst;
      v97 = v75;
      if ( &v97 >= res.positions._Mylast || res.positions._Myfirst > &v97 )
      {
        if ( res.positions._Mylast == res.positions._Myend )
        {
          if ( !(res.positions._Myend - res.positions._Mylast) )
          {
            v82 = res.positions._Mylast - res.positions._Myfirst;
            if ( v82 == 0x3FFFFFFF )
              goto LABEL_130;
            v83 = res.positions._Myend - res.positions._Myfirst;
            if ( 0x3FFFFFFF - (v83 >> 1) >= v83 )
              v84 = (v83 >> 1) + v83;
            else
              v84 = 0;
            if ( v84 < v82 + 1 )
              v84 = v82 + 1;
            std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)&res.positions, v84);
            v76 = res.positions._Mylast;
          }
          v75 = v97;
        }
        if ( !v76 )
          goto LABEL_149;
      }
      else
      {
        v78 = &v97 - res.positions._Myfirst;
        if ( res.positions._Mylast == res.positions._Myend && !(res.positions._Myend - res.positions._Mylast) )
        {
          v79 = res.positions._Mylast - res.positions._Myfirst;
          if ( v79 == 0x3FFFFFFF )
            goto LABEL_130;
          v80 = res.positions._Myend - res.positions._Myfirst;
          if ( 0x3FFFFFFF - (v80 >> 1) >= v80 )
            v81 = (v80 >> 1) + v80;
          else
            v81 = 0;
          if ( v81 < v79 + 1 )
            v81 = v79 + 1;
          std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)&res.positions, v81);
          v76 = res.positions._Mylast;
          v77 = res.positions._Myfirst;
        }
        if ( !v76 )
          goto LABEL_149;
        v75 = v77[v78];
      }
      *v76 = v75;
      v76 = res.positions._Mylast;
LABEL_149:
      ++v73;
      res.positions._Mylast = v76 + 1;
      v74 = v90 + 64;
      v72 = bestLaps._Myfirst;
      v90 += 64;
    }
    while ( v73 < bestLaps._Mylast - bestLaps._Myfirst );
  }
  BestLap::~BestLap(&defaultBestLap);
  v103 = -1;
  std::vector<BestLap>::_Tidy(&bestLaps);
}
void SessionResultProcessor::processRaceResults(SessionResultProcessor *this)
{
  SessionResultProcessor *v1; // ebx
  Sim *v2; // ecx
  unsigned int v3; // esi
  CarAvatar *v4; // ebx
  unsigned int v5; // eax
  int *v6; // esi
  unsigned int v7; // edi
  int v8; // eax
  unsigned int v9; // esi
  int *v10; // edi
  CarAvatar *v11; // eax
  CarAvatar *v12; // eax
  int v13; // eax
  int *v14; // ecx
  int *v15; // edx
  int v16; // edi
  int v17; // ecx
  unsigned int v18; // esi
  unsigned int v19; // esi
  int *v20; // ecx
  int v21; // ecx
  unsigned int v22; // esi
  unsigned int v23; // esi
  int v24; // esi
  CarAvatar *v25; // eax
  CarAvatar *v26; // edi
  Sim *v27; // ecx
  unsigned int v28; // esi
  CarAvatar *v29; // eax
  CarAvatar *v30; // eax
  Lap *v31; // eax
  unsigned int v32; // esi
  Sim *v33; // ecx
  CarAvatar *v34; // eax
  Car *v35; // eax
  Sim *v36; // ecx
  SessionResultProcessor *v37; // eax
  int *v38; // ecx
  int *v39; // esi
  int v40; // edi
  int v41; // ecx
  unsigned int v42; // edx
  unsigned int v43; // edx
  int v44; // ecx
  unsigned int v45; // edx
  unsigned int v46; // edx
  CarAvatar *v47; // eax
  int v48; // eax
  int *v49; // ecx
  int *v50; // esi
  int v51; // edi
  int v52; // ecx
  unsigned int v53; // edx
  unsigned int v54; // edx
  int v55; // ecx
  unsigned int v56; // edx
  unsigned int v57; // edx
  Sim *v58; // ecx
  unsigned int v59; // edx
  CarAvatar *v60; // edi
  Session *v61; // esi
  Sim *v62; // ecx
  int v63; // edi
  unsigned int v64; // eax
  Sim *v65; // ecx
  Lap *v66; // esi
  unsigned int v67; // edi
  unsigned int *v68; // ecx
  unsigned int *v69; // esi
  unsigned int *v70; // eax
  unsigned int *v71; // edi
  float v72; // xmm0_4
  RaceManager *v73; // ecx
  unsigned int v74; // eax
  DataOrderStruct *v75; // esi
  unsigned int v76; // edi
  CarAvatar *v77; // eax
  std::vector<Lap> *v78; // eax
  CarAvatar *v79; // edx
  int v80; // esi
  int v81; // edi
  unsigned int v82; // ebx
  unsigned int v83; // edx
  int v84; // edi
  CarAvatar *v85; // eax
  int v86; // eax
  DataOrderStruct *v87; // esi
  int v88; // edi
  DataOrderStruct *v89; // ecx
  CarAvatar *v90; // eax
  int v91; // eax
  Sim *v92; // ecx
  int v93; // esi
  CarAvatar *v94; // eax
  int v95; // eax
  DataOrderStructRetired *v96; // ecx
  DataOrderStructRetired *v97; // esi
  int v98; // edi
  int v99; // ecx
  unsigned int v100; // edx
  unsigned int v101; // edx
  int v102; // ecx
  unsigned int v103; // edx
  unsigned int v104; // edx
  DataOrderStruct *v105; // edi
  DataOrderStruct *v106; // esi
  unsigned int v107; // ebx
  int v108; // edx
  unsigned int v109; // ebx
  DataOrderStructRetired *v110; // ecx
  int v111; // ecx
  unsigned int v112; // esi
  bool v113; // [esp+17h] [ebp-DDh]
  unsigned int i; // [esp+18h] [ebp-DCh]
  int v115; // [esp+18h] [ebp-DCh]
  int v116; // [esp+18h] [ebp-DCh]
  unsigned int v117; // [esp+18h] [ebp-DCh]
  unsigned int v118; // [esp+1Ch] [ebp-D8h]
  std::vector<DataOrderStruct> totalTimes; // [esp+20h] [ebp-D4h] BYREF
  unsigned int carIndex; // [esp+2Ch] [ebp-C8h]
  std::vector<DataOrderStructRetired> retiredCars; // [esp+30h] [ebp-C4h] BYREF
  unsigned int _Count; // [esp+3Ch] [ebp-B8h]
  CarAvatar *car; // [esp+40h] [ebp-B4h]
  SessionResultProcessor *v124; // [esp+44h] [ebp-B0h]
  int v125; // [esp+48h] [ebp-ACh] BYREF
  int v126; // [esp+4Ch] [ebp-A8h] BYREF
  SessionResultProcessor *v127; // [esp+50h] [ebp-A4h] BYREF
  unsigned int v128; // [esp+54h] [ebp-A0h]
  float v129; // [esp+58h] [ebp-9Ch]
  std::vector<Lap> carAverageLapTime; // [esp+5Ch] [ebp-98h] BYREF
  int v131[2]; // [esp+68h] [ebp-8Ch] BYREF
  unsigned __int64 v132; // [esp+70h] [ebp-84h] BYREF
  int v133; // [esp+78h] [ebp-7Ch]
  Lap l; // [esp+7Ch] [ebp-78h] BYREF
  int v135; // [esp+B8h] [ebp-3Ch]
  unsigned int v136; // [esp+BCh] [ebp-38h]
  int v137; // [esp+F0h] [ebp-4h]

  v1 = this;
  v124 = this;
  SessionResultProcessor::fetchBasicResults(this);
  v2 = v1->sim;
  v3 = 0;
  for ( i = 0; v3 < v2->cars._Mylast - v2->cars._Myfirst; i = v3 )
  {
    if ( !RaceManager::isRaceOver(v2->raceManager, v3) )
    {
      v4 = Sim::getCar(v1->sim, v3);
      v5 = RaceManager::getCarRealTimePosition(v124->sim->raceManager, v4);
      v6 = res.positions._Myfirst;
      v7 = v5;
      v8 = CarAvatar::getGuid(v4);
      v1 = v124;
      v6[v7] = v8;
      v3 = i;
    }
    v2 = v1->sim;
    ++v3;
  }
  if ( !RaceManager::isRaceOver(v1->sim->raceManager, 0) )
  {
    v9 = 0;
    v10 = res.positions._Myfirst;
    if ( res.positions._Mylast - res.positions._Myfirst )
    {
      while ( 1 )
      {
        v11 = Sim::getCar(v1->sim, 0);
        if ( v10[v9] == CarAvatar::getGuid(v11) )
          break;
        ++v9;
        v10 = res.positions._Myfirst;
        if ( v9 >= res.positions._Mylast - res.positions._Myfirst )
          goto LABEL_11;
      }
      _memmove(
        &res.positions._Myfirst[v9],
        &res.positions._Myfirst[v9 + 1],
        ((char *)res.positions._Mylast - (char *)&res.positions._Myfirst[v9 + 1]) & 0xFFFFFFFC);
      --res.positions._Mylast;
    }
LABEL_11:
    v12 = Sim::getCar(v1->sim, 0);
    v13 = CarAvatar::getGuid(v12);
    v14 = res.positions._Mylast;
    v125 = v13;
    v15 = res.positions._Myfirst;
    if ( &v125 >= res.positions._Mylast || res.positions._Myfirst > &v125 )
    {
      if ( res.positions._Mylast == res.positions._Myend )
      {
        if ( !(res.positions._Myend - res.positions._Mylast) )
        {
          v21 = res.positions._Mylast - res.positions._Myfirst;
          if ( v21 == 0x3FFFFFFF )
            std::_Xlength_error("vector<T> too long");
          v22 = res.positions._Myend - res.positions._Myfirst;
          if ( 0x3FFFFFFF - (v22 >> 1) >= v22 )
            v23 = (v22 >> 1) + v22;
          else
            v23 = 0;
          if ( v23 < v21 + 1 )
            v23 = v21 + 1;
          std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)&res.positions, v23);
          v14 = res.positions._Mylast;
          v15 = res.positions._Myfirst;
        }
        v13 = v125;
      }
      if ( !v14 )
        goto LABEL_26;
    }
    else
    {
      v16 = &v125 - res.positions._Myfirst;
      if ( res.positions._Mylast == res.positions._Myend && !(res.positions._Myend - res.positions._Mylast) )
      {
        v17 = res.positions._Mylast - res.positions._Myfirst;
        if ( v17 == 0x3FFFFFFF )
LABEL_16:
          std::_Xlength_error("vector<T> too long");
        v18 = res.positions._Myend - res.positions._Myfirst;
        _Count = v17 + 1;
        if ( 0x3FFFFFFF - (v18 >> 1) >= v18 )
          v19 = (v18 >> 1) + v18;
        else
          v19 = 0;
        if ( v19 < _Count )
          v19 = _Count;
        std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)&res.positions, v19);
        v14 = res.positions._Mylast;
        v15 = res.positions._Myfirst;
      }
      if ( !v14 )
        goto LABEL_26;
      v13 = v15[v16];
    }
    *v14 = v13;
    v14 = res.positions._Mylast;
    v15 = res.positions._Myfirst;
LABEL_26:
    v20 = v14 + 1;
    res.positions._Mylast = v20;
    goto LABEL_41;
  }
  v20 = res.positions._Mylast;
  v15 = res.positions._Myfirst;
LABEL_41:
  v24 = 0;
  if ( v20 - v15 )
  {
    while ( !v15[v24] )
    {
LABEL_48:
      if ( ++v24 >= (unsigned int)(v20 - v15) )
        goto LABEL_49;
    }
    v25 = Sim::getCar(v1->sim, v15[v24]);
    v26 = v25;
    if ( !v25 )
      goto LABEL_52;
    if ( RaceEngineer::getCar(v25->raceEngineer._Myptr)->isRetired )
    {
      disqualifyCar(v26, &res.positions);
LABEL_47:
      v15 = res.positions._Myfirst;
      v20 = res.positions._Mylast;
      goto LABEL_48;
    }
    if ( RaceManager::getLapCount(v1->sim->raceManager, v26) )
      goto LABEL_47;
LABEL_52:
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&res);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::vector<Lap>>>>(res.laps._Myfirst, res.laps._Mylast);
    v32 = 1;
    res.laps._Mylast = res.laps._Myfirst;
    v33 = v1->sim;
    v115 = 1;
    if ( (unsigned int)(v33->cars._Mylast - v33->cars._Myfirst) > 1 )
    {
      do
      {
        v34 = Sim::getCar(v33, v32);
        v35 = RaceEngineer::getCar(v34->raceEngineer._Myptr);
        v36 = v1->sim;
        if ( !v35->isRetired )
        {
          v37 = (SessionResultProcessor *)RaceManager::getCurrentSession(v36->raceManager, (Session *)&l)->laps;
          v38 = res.lapCount._Mylast;
          v39 = res.lapCount._Myfirst;
          v137 = 0;
          v124 = v37;
          v127 = v37;
          if ( (int *)&v127 >= res.lapCount._Mylast || res.lapCount._Myfirst > (int *)&v127 )
          {
            if ( res.lapCount._Mylast == res.lapCount._Myend )
            {
              if ( !(res.lapCount._Myend - res.lapCount._Mylast) )
              {
                v44 = res.lapCount._Mylast - res.lapCount._Myfirst;
                if ( v44 == 0x3FFFFFFF )
                  goto LABEL_16;
                v45 = res.lapCount._Myend - res.lapCount._Myfirst;
                if ( 0x3FFFFFFF - (v45 >> 1) >= v45 )
                  v46 = (v45 >> 1) + v45;
                else
                  v46 = 0;
                if ( v46 < v44 + 1 )
                  v46 = v44 + 1;
                std::vector<ksgui::CustomSpinner *>::_Reallocate(
                  (std::vector<ksgui::CustomSpinner *> *)&res.lapCount,
                  v46);
                v38 = res.lapCount._Mylast;
              }
              v37 = v124;
            }
            if ( v38 )
            {
LABEL_78:
              *v38 = (int)v37;
              v38 = res.lapCount._Mylast;
            }
          }
          else
          {
            v40 = ((char *)&v127 - (char *)res.lapCount._Myfirst) >> 2;
            if ( res.lapCount._Mylast == res.lapCount._Myend && !(res.lapCount._Myend - res.lapCount._Mylast) )
            {
              v41 = res.lapCount._Mylast - res.lapCount._Myfirst;
              if ( v41 == 0x3FFFFFFF )
                goto LABEL_16;
              v42 = res.lapCount._Myend - res.lapCount._Myfirst;
              _Count = v41 + 1;
              if ( 0x3FFFFFFF - (v42 >> 1) >= v42 )
                v43 = (v42 >> 1) + v42;
              else
                v43 = 0;
              if ( v43 < _Count )
                v43 = _Count;
              std::vector<ksgui::CustomSpinner *>::_Reallocate(
                (std::vector<ksgui::CustomSpinner *> *)&res.lapCount,
                v43);
              v38 = res.lapCount._Mylast;
              v39 = res.lapCount._Myfirst;
            }
            if ( v38 )
            {
              v37 = (SessionResultProcessor *)v39[v40];
              goto LABEL_78;
            }
          }
          v137 = -1;
          res.lapCount._Mylast = v38 + 1;
          if ( v136 >= 8 )
            operator delete(l.compound._Myres);
          v136 = 7;
          v135 = 0;
          LOWORD(l.compound._Myres) = 0;
          if ( l.compound._Mysize >= 8 )
            operator delete(*(_DWORD *)&l.isValid);
          goto LABEL_109;
        }
        v47 = Sim::getCar(v36, v32);
        v48 = RaceManager::getLapCount(v1->sim->raceManager, v47);
        v49 = res.lapCount._Mylast;
        v50 = res.lapCount._Myfirst;
        v126 = v48;
        if ( &v126 >= res.lapCount._Mylast || res.lapCount._Myfirst > &v126 )
        {
          if ( res.lapCount._Mylast == res.lapCount._Myend )
          {
            if ( !(res.lapCount._Myend - res.lapCount._Mylast) )
            {
              v55 = res.lapCount._Mylast - res.lapCount._Myfirst;
              if ( v55 == 0x3FFFFFFF )
                goto LABEL_16;
              v56 = res.lapCount._Myend - res.lapCount._Myfirst;
              if ( 0x3FFFFFFF - (v56 >> 1) >= v56 )
                v57 = (v56 >> 1) + v56;
              else
                v57 = 0;
              if ( v57 < v55 + 1 )
                v57 = v55 + 1;
              std::vector<ksgui::CustomSpinner *>::_Reallocate(
                (std::vector<ksgui::CustomSpinner *> *)&res.lapCount,
                v57);
              v49 = res.lapCount._Mylast;
            }
            v48 = v126;
          }
          if ( !v49 )
            goto LABEL_108;
        }
        else
        {
          v51 = &v126 - res.lapCount._Myfirst;
          if ( res.lapCount._Mylast == res.lapCount._Myend && !(res.lapCount._Myend - res.lapCount._Mylast) )
          {
            v52 = res.lapCount._Mylast - res.lapCount._Myfirst;
            if ( v52 == 0x3FFFFFFF )
              goto LABEL_16;
            v53 = res.lapCount._Myend - res.lapCount._Myfirst;
            _Count = v52 + 1;
            if ( 0x3FFFFFFF - (v53 >> 1) >= v53 )
              v54 = (v53 >> 1) + v53;
            else
              v54 = 0;
            if ( v54 < _Count )
              v54 = _Count;
            std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)&res.lapCount, v54);
            v49 = res.lapCount._Mylast;
            v50 = res.lapCount._Myfirst;
          }
          if ( !v49 )
            goto LABEL_108;
          v48 = v50[v51];
        }
        *v49 = v48;
        v49 = res.lapCount._Mylast;
LABEL_108:
        res.lapCount._Mylast = v49 + 1;
LABEL_109:
        v33 = v1->sim;
        v32 = v115 + 1;
        v115 = v32;
      }
      while ( v32 < v33->cars._Mylast - v33->cars._Myfirst );
    }
  }
  else
  {
LABEL_49:
    carAverageLapTime._Myfirst = 0;
    carAverageLapTime._Mylast = 0;
    carAverageLapTime._Myend = 0;
    v27 = v1->sim;
    v28 = 0;
    v137 = 1;
    if ( v27->cars._Mylast - v27->cars._Myfirst )
    {
      do
      {
        v29 = Sim::getCar(v27, v28);
        if ( RaceManager::getLapCount(v1->sim->raceManager, v29) )
        {
          v30 = Sim::getCar(v1->sim, v28);
          v31 = getAverageLap(&l, v1->sim->raceManager, v30);
          LOBYTE(v137) = 2;
        }
        else
        {
          l.splits._Myfirst = 0;
          l.splits._Mylast = 0;
          l.splits._Myend = 0;
          l.compound._Myres = 7;
          l.compound._Mysize = 0;
          l.compound._Bx._Buf[0] = 0;
          l.time = 0;
          l.isValid = 0;
          l.cuts = 0;
          LOBYTE(v137) = 3;
          v31 = &l;
        }
        std::vector<Lap>::push_back(&carAverageLapTime, v31);
        LOBYTE(v137) = 1;
        if ( l.compound._Myres >= 8 )
          operator delete(l.compound._Bx._Ptr);
        l.compound._Myres = 7;
        l.compound._Bx._Buf[0] = 0;
        l.compound._Mysize = 0;
        if ( l.splits._Myfirst )
        {
          std::_Container_base0::_Orphan_all(&l.splits);
          operator delete(l.splits._Myfirst);
        }
        v27 = v1->sim;
        ++v28;
      }
      while ( v28 < v1->sim->cars._Mylast - v1->sim->cars._Myfirst );
    }
    v58 = v1->sim;
    v59 = 1;
    carIndex = 1;
    if ( (unsigned int)(v58->cars._Mylast - v58->cars._Myfirst) > 1 )
    {
      v116 = 1;
      v128 = 48;
      do
      {
        v60 = Sim::getCar(v58, v59);
        car = v60;
        if ( !RaceEngineer::getCar(v60->raceEngineer._Myptr)->isRetired
          && !RaceManager::isRaceOver(v1->sim->raceManager, carIndex) )
        {
          v61 = RaceManager::getCurrentSession(v1->sim->raceManager, (Session *)&l);
          v62 = v1->sim;
          LOBYTE(v137) = 4;
          v63 = v61->laps - RaceManager::getLapCount(v62->raceManager, v60);
          LOBYTE(v137) = 1;
          if ( v136 >= 8 )
            operator delete(l.compound._Myres);
          v136 = 7;
          v135 = 0;
          LOWORD(l.compound._Myres) = 0;
          if ( l.compound._Mysize >= 8 )
            operator delete(*(_DWORD *)&l.isValid);
          v113 = RaceManager::getCurrentSession(v1->sim->raceManager, (Session *)&l)->isOver;
          if ( v136 >= 8 )
            operator delete(l.compound._Myres);
          v136 = 7;
          v135 = 0;
          LOWORD(l.compound._Myres) = 0;
          if ( l.compound._Mysize >= 8 )
            operator delete(*(_DWORD *)&l.isValid);
          if ( v113 )
            v63 = 1;
          v118 = v63;
          v64 = RaceManager::getLapCount(v1->sim->raceManager, car);
          v65 = v1->sim;
          _Count = v64;
          if ( v64 < v63 + RaceManager::getLapCount(v65->raceManager, car) )
          {
            do
            {
              v66 = carAverageLapTime._Myfirst;
              v67 = v128;
              l.time = carAverageLapTime._Myfirst[v128 / 0x30].time;
              std::vector<Mesh *>::vector<Mesh *>(
                (std::vector<TyreThermalPatch *> *)&l.splits,
                (const std::vector<TyreThermalPatch *> *)&carAverageLapTime._Myfirst[v128 / 0x30].splits);
              l.cuts = *(unsigned int *)((char *)&v66->cuts + v67);
              l.isValid = *(&v66->isValid + v67);
              l.compound._Bx._Buf[0] = 0;
              LOBYTE(v137) = 5;
              l.compound._Myres = 7;
              l.compound._Mysize = 0;
              std::wstring::assign(&l.compound, (const std::wstring *)((char *)&v66->compound + v67), 0, 0xFFFFFFFF);
              LOBYTE(v137) = 6;
              v129 = (float)((float)((float)((float)_rand() * 0.000030518509) * 2.0) - 1.0) * delta;
              v68 = l.splits._Myfirst;
              v69 = l.splits._Myfirst;
              l.time = (unsigned int)(float)((float)l.time + v129);
              v70 = l.splits._Mylast;
              v71 = l.splits._Mylast;
              if ( l.splits._Myfirst != l.splits._Mylast )
              {
                while ( 1 )
                {
                  v72 = (float)(unsigned int)(v70 - v68);
                  *v69 = (unsigned int)(float)((float)(v129 / v72) + (float)*v69);
                  if ( ++v69 == v71 )
                    break;
                  v70 = l.splits._Mylast;
                  v68 = l.splits._Myfirst;
                }
              }
              std::vector<Lap>::push_back(&res.laps._Myfirst[v116], &l);
              LOBYTE(v137) = 1;
              if ( l.compound._Myres >= 8 )
                operator delete(l.compound._Bx._Ptr);
              l.compound._Myres = 7;
              l.compound._Mysize = 0;
              l.compound._Bx._Buf[0] = 0;
              if ( l.splits._Myfirst )
              {
                std::_Container_base0::_Orphan_all(&l.splits);
                operator delete(l.splits._Myfirst);
              }
              v73 = v1->sim->raceManager;
              ++_Count;
            }
            while ( _Count < v118 + RaceManager::getLapCount(v73, car) );
          }
        }
        v58 = v1->sim;
        v128 += 48;
        v59 = carIndex + 1;
        ++v116;
        v74 = v58->cars._Mylast - v58->cars._Myfirst;
        carIndex = v59;
      }
      while ( v59 < v74 );
    }
    v75 = 0;
    totalTimes._Myfirst = 0;
    totalTimes._Mylast = 0;
    totalTimes._Myend = 0;
    retiredCars._Myfirst = 0;
    retiredCars._Mylast = 0;
    retiredCars._Myend = 0;
    v76 = 0;
    LOBYTE(v137) = 8;
    carIndex = 0;
    if ( res.laps._Mylast - res.laps._Myfirst )
    {
      car = 0;
      do
      {
        v77 = Sim::getCar(v1->sim, v76);
        if ( RaceEngineer::getCar(v77->raceEngineer._Myptr)->isRetired )
        {
          v90 = Sim::getCar(v1->sim, v76);
          v91 = RaceManager::getLapCount(v1->sim->raceManager, v90);
          v92 = v1->sim;
          v93 = v91;
          v129 = *(float *)&v91;
          v94 = Sim::getCar(v92, v76);
          v95 = CarAvatar::getGuid(v94);
          v96 = retiredCars._Mylast;
          v131[1] = v93;
          v97 = retiredCars._Myfirst;
          v131[0] = v95;
          if ( (DataOrderStructRetired *)v131 >= retiredCars._Mylast
            || retiredCars._Myfirst > (DataOrderStructRetired *)v131 )
          {
            if ( retiredCars._Mylast == retiredCars._Myend )
            {
              if ( !(retiredCars._Myend - retiredCars._Mylast) )
              {
                v102 = retiredCars._Mylast - retiredCars._Myfirst;
                if ( v102 == 0x1FFFFFFF )
                  goto LABEL_16;
                v103 = retiredCars._Myend - retiredCars._Myfirst;
                v118 = v102 + 1;
                if ( 0x1FFFFFFF - (v103 >> 1) >= v103 )
                  v104 = (v103 >> 1) + v103;
                else
                  v104 = 0;
                if ( v104 < v118 )
                  v104 = v102 + 1;
                std::vector<ReplayLap>::_Reallocate((std::vector<SplineIndexBound> *)&retiredCars, v104);
                v96 = retiredCars._Mylast;
              }
              v95 = v131[0];
            }
            if ( v96 )
            {
              v96->avatarIndex = v95;
              *(float *)&v96->lapCount = v129;
              v96 = retiredCars._Mylast;
            }
          }
          else
          {
            v98 = ((char *)v131 - (char *)retiredCars._Myfirst) >> 3;
            if ( retiredCars._Mylast == retiredCars._Myend && !(retiredCars._Myend - retiredCars._Mylast) )
            {
              v99 = retiredCars._Mylast - retiredCars._Myfirst;
              if ( v99 == 0x1FFFFFFF )
                goto LABEL_16;
              v100 = retiredCars._Myend - retiredCars._Myfirst;
              v118 = v99 + 1;
              if ( 0x1FFFFFFF - (v100 >> 1) >= v100 )
                v101 = (v100 >> 1) + v100;
              else
                v101 = 0;
              if ( v101 < v118 )
                v101 = v99 + 1;
              std::vector<ReplayLap>::_Reallocate((std::vector<SplineIndexBound> *)&retiredCars, v101);
              v96 = retiredCars._Mylast;
              v97 = retiredCars._Myfirst;
            }
            if ( v96 )
            {
              v96->avatarIndex = v97[v98].avatarIndex;
              v96->lapCount = v97[v98].lapCount;
              v96 = retiredCars._Mylast;
            }
            v76 = carIndex;
          }
          v75 = totalTimes._Mylast;
          retiredCars._Mylast = v96 + 1;
        }
        else
        {
          v78 = res.laps._Myfirst;
          v79 = car;
          v117 = 0;
          v80 = *(int *)((char *)&car->__vftable + (unsigned int)res.laps._Myfirst);
          v81 = *(int *)((char *)&car->game + (unsigned int)res.laps._Myfirst);
          if ( v80 != v81 )
          {
            v82 = 0;
            do
            {
              l.time = *(_DWORD *)v80;
              std::vector<Mesh *>::vector<Mesh *>(
                (std::vector<TyreThermalPatch *> *)&l.splits,
                (const std::vector<TyreThermalPatch *> *)(v80 + 4));
              l.cuts = *(_DWORD *)(v80 + 16);
              l.isValid = *(_BYTE *)(v80 + 20);
              l.compound._Bx._Buf[0] = 0;
              LOBYTE(v137) = 9;
              l.compound._Myres = 7;
              l.compound._Mysize = 0;
              std::wstring::assign(&l.compound, (const std::wstring *)(v80 + 24), 0, 0xFFFFFFFF);
              v82 += l.time;
              LOBYTE(v137) = 8;
              if ( l.compound._Myres >= 8 )
                operator delete(l.compound._Bx._Ptr);
              l.compound._Myres = 7;
              l.compound._Mysize = 0;
              l.compound._Bx._Buf[0] = 0;
              if ( l.splits._Myfirst )
              {
                std::_Container_base0::_Orphan_all(&l.splits);
                operator delete(l.splits._Myfirst);
              }
              v80 += 48;
            }
            while ( v80 != v81 );
            v78 = res.laps._Myfirst;
            v79 = car;
            v117 = v82;
            v1 = v124;
          }
          v83 = (int)((unsigned __int64)(715827883i64
                                       * (*(char **)((char *)&v78->_Mylast + (_DWORD)v79)
                                        - *(char **)((char *)&v78->_Myfirst + (_DWORD)v79))) >> 32) >> 3;
          v84 = v83 + (v83 >> 31);
          v85 = Sim::getCar(v1->sim, carIndex);
          v86 = CarAvatar::getGuid(v85);
          v87 = totalTimes._Mylast;
          v132 = __PAIR64__(v117, v86);
          v133 = v84;
          if ( (DataOrderStruct *)&v132 >= totalTimes._Mylast || totalTimes._Myfirst > (DataOrderStruct *)&v132 )
          {
            if ( totalTimes._Mylast == totalTimes._Myend )
            {
              std::vector<RealTimeCarDesc>::_Reserve((std::vector<TimeLineStatus> *)&totalTimes, 1u);
              v87 = totalTimes._Mylast;
            }
            if ( v87 )
            {
              *(_QWORD *)&v87->avatarIndex = v132;
              v87->lapCount = v84;
              v87 = totalTimes._Mylast;
            }
            v76 = carIndex;
            v75 = v87 + 1;
            totalTimes._Mylast = v75;
          }
          else
          {
            v88 = ((char *)&v132 - (char *)totalTimes._Myfirst) / 12;
            if ( totalTimes._Mylast == totalTimes._Myend )
            {
              std::vector<RealTimeCarDesc>::_Reserve((std::vector<TimeLineStatus> *)&totalTimes, 1u);
              v87 = totalTimes._Mylast;
            }
            v89 = totalTimes._Myfirst;
            if ( v87 )
            {
              *(_QWORD *)&v87->avatarIndex = *(_QWORD *)&totalTimes._Myfirst[v88].avatarIndex;
              v87->lapCount = v89[v88].lapCount;
              v87 = totalTimes._Mylast;
            }
            v76 = carIndex;
            v75 = v87 + 1;
            totalTimes._Mylast = v75;
          }
        }
        ++v76;
        car = (CarAvatar *)((char *)car + 12);
        carIndex = v76;
      }
      while ( v76 < res.laps._Mylast - res.laps._Myfirst );
    }
    std::_Sort<DataOrderStruct *,int,_lambda_052f79f8740a582ea4953223732c2846_>(
      totalTimes._Myfirst,
      v75,
      v75 - totalTimes._Myfirst,
      (SessionResultProcessor::processRaceResults::__l71::<lambda_052f79f8740a582ea4953223732c2846>)v118);
    std::_Sort<DataOrderStructRetired *,int,_lambda_eb7ef350e7829f5db0d16840c7b892e3_>(
      retiredCars._Myfirst,
      retiredCars._Mylast,
      retiredCars._Mylast - retiredCars._Myfirst,
      (SessionResultProcessor::processRaceResults::__l72::<lambda_eb7ef350e7829f5db0d16840c7b892e3>)v118);
    v105 = totalTimes._Mylast;
    v106 = totalTimes._Myfirst;
    v107 = 0;
    if ( totalTimes._Mylast - totalTimes._Myfirst )
    {
      v108 = 0;
      do
      {
        res.positions._Myfirst[v107] = v106[v108].avatarIndex;
        v105 = totalTimes._Mylast;
        ++v107;
        v106 = totalTimes._Myfirst;
        ++v108;
      }
      while ( v107 < totalTimes._Mylast - totalTimes._Myfirst );
    }
    v109 = 0;
    v110 = retiredCars._Myfirst;
    if ( retiredCars._Mylast - retiredCars._Myfirst )
    {
      while ( 1 )
      {
        v111 = v110[v109].avatarIndex;
        v112 = v109 + v105 - v106;
        ++v109;
        res.positions._Myfirst[v112] = v111;
        v110 = retiredCars._Myfirst;
        v106 = totalTimes._Myfirst;
        if ( v109 >= retiredCars._Mylast - retiredCars._Myfirst )
          break;
        v105 = totalTimes._Mylast;
      }
    }
    LOBYTE(v137) = 7;
    if ( v110 )
    {
      std::_Container_base0::_Orphan_all(&retiredCars);
      operator delete(retiredCars._Myfirst);
      v106 = totalTimes._Myfirst;
      retiredCars._Myfirst = 0;
      retiredCars._Mylast = 0;
      retiredCars._Myend = 0;
    }
    LOBYTE(v137) = 1;
    if ( v106 )
    {
      std::_Container_base0::_Orphan_all(&totalTimes);
      operator delete(totalTimes._Myfirst);
      totalTimes._Myfirst = 0;
      totalTimes._Mylast = 0;
      totalTimes._Myend = 0;
    }
    v137 = -1;
    if ( carAverageLapTime._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&carAverageLapTime);
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(carAverageLapTime._Myfirst, carAverageLapTime._Mylast);
      operator delete(carAverageLapTime._Myfirst);
    }
  }
}
