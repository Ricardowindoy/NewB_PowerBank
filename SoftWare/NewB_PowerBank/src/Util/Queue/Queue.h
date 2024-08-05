#ifndef Queue_H
#define Queue_H

class Queue {
    public:
        Queue();
        ~Queue();
    public:
        // 基于性能考虑 iCap仅支持2的次方 传入其他数字将会向下取2的次方
        void SetCap(int iCap);
        float GetAverage(){return 0;};
        float AddItem(float fItem);

    private:
        void CreatDataArray();
    private:
        int m_iQueueCap;
        int m_iQueueSize;
        float* m_pDataArray;
        float m_fAverage;
        int m_iPos;
        // 计算总和最好做溢出检测
        float m_fSum;
        bool m_bSumIsNew;
};

#endif