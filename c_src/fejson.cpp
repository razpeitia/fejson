#include <string>
#include <cstring>
#include <iostream>
#include "erl_nif.h"

#include "simdjson/jsonparser.h"
using namespace simdjson;

static int
load(ErlNifEnv* env, void** priv, ERL_NIF_TERM load_info)
{
    return 0;
}

static int
upgrade(ErlNifEnv* env, void** priv, void** old_priv, ERL_NIF_TERM load_info)
{
    return 0;
}

static void
unload(ErlNifEnv* env, void* priv)
{
    return;
}

static ERL_NIF_TERM
encode(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    return enif_make_int(env, 4);
}

static ERL_NIF_TERM
decode(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    if(!enif_is_binary(env, argv[0])) {
        return enif_make_badarg(env);
    }
    ErlNifBinary bin;

    if(!enif_inspect_binary(env, argv[0], &bin)) {
        return 0;
    }

    std::string mystring = std::string(bin.data, bin.data + bin.size);
    std::cout << mystring << " " << mystring.size() << std::endl;
    
    //ParsedJson pj;
    //pj.allocate_capacity(mystring.size());
    /*
    // std::string may not overallocate so a copy will be needed
    const int res = json_parse(mystring, pj); // do the parsing, return 0 on success
    if(pj.is_valid()) {
        return enif_make_atom(env, "true");
    } else {
        return enif_make_atom(env, "false");
    }
    */
    return enif_make_int(env, 4);
}

static ErlNifFunc nif_funcs[] = {
    {"encode", 1, encode},
    {"decode", 1, decode},
};

ERL_NIF_INIT(fejson, nif_funcs, &load, NULL, &upgrade, &unload);