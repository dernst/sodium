#include <Rinternals.h>
#include <sodium.h>

SEXP R_diffie_pubkey(SEXP key){
  if(LENGTH(key) != crypto_scalarmult_SCALARBYTES)
    Rf_error("Invalid key, must be exactly %d bytes", crypto_scalarmult_SCALARBYTES);
  SEXP res = allocVector(RAWSXP, crypto_scalarmult_BYTES);
  if(crypto_scalarmult_base(RAW(res), RAW(key)))
    Rf_error("Failed crypto_scalarmult_base");
  return res;
}

SEXP R_diffie_secret(SEXP key, SEXP pubkey){
  if(LENGTH(key) != crypto_scalarmult_SCALARBYTES)
    Rf_error("Invalid key, must be exactly %d bytes", crypto_scalarmult_SCALARBYTES);
  if(LENGTH(pubkey) != crypto_scalarmult_BYTES)
    Rf_error("Invalid pubkey, must be exactly %d bytes", crypto_scalarmult_BYTES);
  SEXP res = allocVector(RAWSXP, crypto_scalarmult_BYTES);
  if(crypto_scalarmult(RAW(res), RAW(key), RAW(pubkey)))
    Rf_error("Failed crypto_scalarmult");
  return res;
}
