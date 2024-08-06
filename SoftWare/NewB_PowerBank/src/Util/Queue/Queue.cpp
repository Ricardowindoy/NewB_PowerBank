#include "Queue.h"
#include <cstdlib>
#include <cstring>

Queue::Queue() {
        m_iQueueCap = 0;
        m_iQueueSize = 0;
        m_pDataArray = nullptr;
        m_fAverage = 0;
        m_iPos = 0;
        m_fSum = 0;
        m_bSumIsNew = false;
}

Queue::~Queue() {
    if (m_pDataArray != nullptr)
    {
        delete [] m_pDataArray;
    }
    m_pDataArray = nullptr;
}

void Queue::CreatDataArray() {
    delete [] m_pDataArray;
    m_pDataArray = nullptr;

    if (m_iQueueCap == 0)
        SetCap(2);

    m_pDataArray = new float[m_iQueueCap];
    memset(m_pDataArray, 0, sizeof(m_pDataArray) * sizeof(m_pDataArray[0]));
}

void Queue::SetCap(int iCap) {
    for(int i = 31; i; i++)
    {
        if(iCap & 1 << i) {
            iCap = iCap & 1 << i;
            break;
        }
    }

    if(iCap < 4)
        iCap = 4;

    m_iQueueCap = iCap;
}

float Queue::AddItem(float fItem) {
    m_bSumIsNew = false;
    if (m_pDataArray == nullptr)
        CreatDataArray();

    m_fSum -= m_pDataArray[(m_iPos + 1) & (m_iQueueCap - 1)];
    m_fSum += fItem;
    m_pDataArray[m_iPos++ & (m_iQueueCap - 1)] = fItem;

    m_bSumIsNew = true;

    if (!m_bSumIsNew)
    {
        /* code */
    }

    return m_fSum / m_iQueueCap;
};