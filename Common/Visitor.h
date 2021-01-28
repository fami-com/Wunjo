//
// Created by V on 2021-01-28.
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
