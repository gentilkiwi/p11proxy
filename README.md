# p11proxy

**`p11proxy`** is a little `PKCS#11` Proxy designed to deal with PUK on Gemalto IDPrime smartcards

## Gemalto IDPrime Admin key / PUK normal behavior


## P11 Proxy to Gemalto IDPrime behavior


## Clarification

You can use:
- `PR_FW` macro to forward a `PKCS#11` standard fonction to the original one in `idprimepkcs11*.dll`
- `PR_HK` macro to forward a `PKCS#11` standard fonction to a new one called `HOOK_C_*`