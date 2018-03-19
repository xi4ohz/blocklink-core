﻿/**
* Author: wengqiang (email: wens.wq@gmail.com  site: qiangweng.site)
*
* Copyright © 2015--2018 . All rights reserved.
*
* File: util.cpp
* Date: 2018-03-19
*/

#include <graphene/crosschain_privatekey_management/util.hpp>


namespace graphene {
    namespace privatekey_management {


        std::string get_address_by_pubkey(const std::string& pubkey_hex_str, uint8_t version)
        {
            //get public key
            libbitcoin::wallet::ec_public libbitcoin_pub(pubkey_hex_str);
            FC_ASSERT(libbitcoin_pub != libbitcoin::wallet::ec_public(), "the pubkey hex str is in valid!");

            auto addr = libbitcoin_pub.to_payment_address(version);

            return addr.encoded();

        }


    }
}

