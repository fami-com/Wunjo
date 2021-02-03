//
// This file is licensed under MPL 2.0, GNU GPL v2.0+ and GNU LGPL v2.1+
// For more information about the licensing, see the LICENSE file in the project root
// Copyright (c) 2021 - 2021 fami-com
//

#ifndef WUNJO_VISITOR_H
#define WUNJO_VISITOR_H

template<class... Ts>
struct overload : Ts... {
    using Ts::operator()...;
};
template<class... Ts>
overload(Ts...) -> overload<Ts...>;

#endif //WUNJO_VISITOR_H
