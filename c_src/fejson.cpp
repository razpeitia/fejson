#include <cstring>
#include "erl_nif.h"

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
    return enif_make_int(env, 2);
}

static ErlNifFunc nif_funcs[] = {
    {"encode", 1, encode},
    {"decode", 1, decode},
};

ERL_NIF_INIT(fejson, nif_funcs, &load, NULL, &upgrade, &unload);