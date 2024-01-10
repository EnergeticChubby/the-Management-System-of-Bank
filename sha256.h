#pragma once
/*
 * Copyright (c)
 * Filename:    sha256.h
 * Brief:       SHA256�㷨ʵ��
 * Depend:      C++11
 *
 * Version:     V1.0.0
 * Date:        2019/11/08-2019/11/13
 * Author:      LucianY
 * Note:        ���ΰ汾��
 *
 * Version:     V2.0.0
 * Date:        2023/01/04
 * Author:      LucianY
 * Note:        1�������Ż���ʹ�õ���ģʽ��
 *              2��debug��֧�ּ��ܿ��ַ�����
 *              3�������Ż���
 *
 * Attention:   ������Ϣ��������ʱ���õ�������ָ����ʹ���������ߵõ�����ָ�ƿ��ܲ���ͬ��ԭ���ǲ�ͬƽ̨���ĵı��뷽ʽ��ͬ��
 */

#ifndef LY_SHA256_H
#define LY_SHA256_H
#include "MFCApplication3Dlg.h"
#include <cstdint>

#include <string>
#include <vector>

namespace Ly {

    /**
     * @brief SHA256������
    */
    class Sha256 {
    public:
        //! ��ȡ����
        inline static Sha256& getInstance()
        {
            static Sha256 instance;
            return instance;
        }

        /**
         * @brief: ʹ��SHA256�㷨������������Ϣ����ȡ����ָ�ƣ�
         * @param[in] message: ������Ϣ
         * @return: ժҪ������ָ�ƣ�
        */
        std::vector<uint8_t> encrypt(std::vector<uint8_t> message) const;

        /**
         * @brief: ��ȡʮ�����Ʊ�ʾ����ϢժҪ������ָ�ƣ�
         * @param[in] message: ������Ϣ
         * @return: ʮ�����Ʊ�ʾ����ϢժҪ������ָ�ƣ�
        */
        std::string getHexMessageDigest(const std::string& message) const;

    protected:
        /// SHA256�㷨�ж����6���߼����� ///

        inline uint32_t ch(uint32_t x, uint32_t y, uint32_t z) const noexcept
        {
            return (x & y) ^ ((~x) & z);
        }

        inline uint32_t maj(uint32_t x, uint32_t y, uint32_t z) const noexcept
        {
            return (x & y) ^ (x & z) ^ (y & z);
        }

        inline uint32_t bigSigma0(uint32_t x) const noexcept
        {
            return (x >> 2 | x << 30) ^ (x >> 13 | x << 19) ^ (x >> 22 | x << 10);
        }

        inline uint32_t bigSigma1(uint32_t x) const noexcept
        {
            return (x >> 6 | x << 26) ^ (x >> 11 | x << 21) ^ (x >> 25 | x << 7);
        }

        inline uint32_t smallSigma0(uint32_t x) const noexcept
        {
            return (x >> 7 | x << 25) ^ (x >> 18 | x << 14) ^ (x >> 3);
        }

        inline uint32_t smallSigma1(uint32_t x) const noexcept
        {
            return (x >> 17 | x << 15) ^ (x >> 19 | x << 13) ^ (x >> 10);
        }

        /**
         * @brief: SHA256�㷨��������Ϣ��Ԥ���������������������ء��͡����ӳ���ֵ��
                ����������: �ڱ���ĩβ������䣬�Ȳ���һ������Ϊ1��Ȼ�󶼲�0��ֱ�����������512ȡģ��������448����Ҫע����ǣ���Ϣ���������䡣
                ���ӳ���ֵ: ��һ��64λ����������ʾԭʼ��Ϣ�����ǰ����Ϣ���ĳ��ȣ������䲹���Ѿ�����������������Ϣ���档
         * @param[in][out] message: ����������Ϣ
        */
        void preprocessing(std::vector<uint8_t>& message) const;

        /**
         * @brief: ����Ϣ�ֽ��������64Byte��С�����ݿ�
         * @param[in] message: ������Ϣ������Ϊ64Byte�ı���
         * @return: ������ݿ�
        */
        std::vector<std::vector<uint8_t>> breakTextInto64ByteChunks(const std::vector<uint8_t>& message) const;

        /**
         * @brief: ��64Byte��С�����ݿ飬�����64��4Byte��С���֡�
                �����㷨��ǰ16����ֱ�������ݿ�ֽ�õ���������������µ�����ʽ�õ���
                W[t] = smallSigma1(W[t-2]) + W[t-7] + smallSigma0(W[t-15]) + W[t-16]
         * @param[in] chunk: �������ݿ飬��СΪ64Byte
         * @return: �����
        */
        std::vector<uint32_t> structureWords(const std::vector<uint8_t>& chunk) const;

        /**
         * @breif: ����64��4Byte��С���֣�����64��ѭ������
         * @param[in] words: 64��4Byte��С����
         * @param[in][out] message_digest: ��ϢժҪ
        */
        void transform(const std::vector<uint32_t>& words, std::vector<uint32_t>& message_digest) const;

        /**
         * @brief: ������յĹ�ϣֵ������ָ�ƣ�
         * @param[in] input: ����Ϊ32bit�Ĺ�ϣֵ
         * @return: ����Ϊ8bit�Ĺ�ϣֵ
        */
        std::vector<uint8_t> produceFinalHashValue(const std::vector<uint32_t>& input) const;

    private:
        /* ����ģʽ */
        Sha256() = default;

        Sha256(const Sha256&) = delete;
        Sha256& operator=(const Sha256&) = delete;

        Sha256(Sha256&&) = delete;
        Sha256& operator=(Sha256&&) = delete;

        ~Sha256() = default;


        // ��SHA256�㷨�еĳ�ʼ��ϢժҪ����Щ�����Ƕ���Ȼ����ǰ8��������ƽ������С������ȡǰ32bit����
        static const std::vector<uint32_t> initial_message_digest_;

        // ��SHA256�㷨�У��õ�64����������Щ�����Ƕ���Ȼ����ǰ64����������������С������ȡǰ32bit����
        static const std::vector<uint32_t> add_constant_;
    };

} // namespace Ly
#endif // LY_SHA256_H