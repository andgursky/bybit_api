#ifndef BYBIT_ENDPOINTS_H
#define BYBIT_ENDPOINTS_H

#include "bybit/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Generated from bybit-exchange/docs d5a43d2d010c4468e3f7d992408eaff88a48068a. Do not edit. */

typedef struct bybit_endpoint {
    const char *name;
    const char *method;
    const char *path;
    const char *title;
    const char *doc;
    const char *required;
    int auth_required;
} bybit_endpoint;

size_t bybit_endpoint_count(void);
const bybit_endpoint *bybit_endpoint_at(size_t index);
const bybit_endpoint *bybit_endpoint_find(const char *method, const char *path);
bybit_err bybit_endpoint_invoke(bybit_client *client, const bybit_endpoint *endpoint,
                                const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Manual Borrow. POST /v5/account/borrow. Auth: private. Required: coin, amount. */
bybit_err bybit_account_borrow(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Borrow History. GET /v5/account/borrow-history. Auth: private. Required: none. */
bybit_err bybit_account_borrow_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Collateral Info. GET /v5/account/collateral-info. Auth: private. Required: none. */
bybit_err bybit_account_collateral_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Demo Trading Service. POST /v5/account/demo-apply-money. Auth: private. Required: none. */
bybit_err bybit_account_demo_apply_money(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Fee Rate. GET /v5/account/fee-rate. Auth: private. Required: none. */
bybit_err bybit_account_fee_rate(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Account Info. GET /v5/account/info. Auth: private. Required: none. */
bybit_err bybit_account_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Account Instruments Info. GET /v5/account/instruments-info. Auth: private. Required: category. */
bybit_err bybit_account_instruments_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Set MMP. POST /v5/account/mmp-modify. Auth: private. Required: baseCoin, window, frozenPeriod, qtyLimit, deltaLimit. */
bybit_err bybit_account_mmp_modify(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Reset MMP. POST /v5/account/mmp-reset. Auth: private. Required: baseCoin. */
bybit_err bybit_account_mmp_reset(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get MMP State. GET /v5/account/mmp-state. Auth: private. Required: baseCoin. */
bybit_err bybit_account_mmp_state(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Manual Repay Without Asset Conversion. POST /v5/account/no-convert-repay. Auth: private. Required: coin. */
bybit_err bybit_account_no_convert_repay(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Option Asset Info. GET /v5/account/option-asset-info. Auth: private. Required: none. */
bybit_err bybit_account_option_asset_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Pay Info. GET /v5/account/pay-info. Auth: private. Required: none. */
bybit_err bybit_account_pay_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get DCP Info. GET /v5/account/query-dcp-info. Auth: private. Required: none. */
bybit_err bybit_account_query_dcp_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Repay Liability. POST /v5/account/quick-repayment. Auth: private. Required: none. */
bybit_err bybit_account_quick_repayment(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Manual Repay. POST /v5/account/repay. Auth: private. Required: none. */
bybit_err bybit_account_repay(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Set Collateral Coin. POST /v5/account/set-collateral-switch. Auth: private. Required: coin, collateralSwitch. */
bybit_err bybit_account_set_collateral_switch(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Batch Set Collateral Coin. POST /v5/account/set-collateral-switch-batch. Auth: private. Required: request. */
bybit_err bybit_account_set_collateral_switch_batch(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Set Delta Neutral Mode. POST /v5/account/set-delta-mode. Auth: private. Required: deltaEnable. */
bybit_err bybit_account_set_delta_mode(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Set Spot Hedging. POST /v5/account/set-hedging-mode. Auth: private. Required: setHedgingMode. */
bybit_err bybit_account_set_hedging_mode(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Set Price Limit Behaviour. POST /v5/account/set-limit-px-action. Auth: private. Required: category, modifyEnable. */
bybit_err bybit_account_set_limit_px_action(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Set Margin Mode. POST /v5/account/set-margin-mode. Auth: private. Required: setMarginMode. */
bybit_err bybit_account_set_margin_mode(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get SMP Group ID. GET /v5/account/smp-group. Auth: private. Required: none. */
bybit_err bybit_account_smp_group(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Trade Info For Analysis. GET /v5/account/trade-info-for-analysis. Auth: private. Required: symbol. */
bybit_err bybit_account_trade_info_for_analysis(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Transaction Log. GET /v5/account/transaction-log. Auth: private. Required: none. */
bybit_err bybit_account_transaction_log(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Upgrade to Unified Account Pro. POST /v5/account/upgrade-to-uta. Auth: private. Required: none. */
bybit_err bybit_account_upgrade_to_uta(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Trade Behaviour Config. GET /v5/account/user-setting-config. Auth: private. Required: none. */
bybit_err bybit_account_user_setting_config(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Wallet Balance. GET /v5/account/wallet-balance. Auth: private. Required: accountType. */
bybit_err bybit_account_wallet_balance(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Transferable Amount (Unified). GET /v5/account/withdrawal. Auth: private. Required: coinName. */
bybit_err bybit_account_withdrawal(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Affiliate User List. GET /v5/affiliate/aff-user-list. Auth: private. Required: none. */
bybit_err bybit_affiliate_aff_user_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Affiliate Sub-Affiliate List. GET /v5/affiliate/affiliate-sub-list. Auth: private. Required: none. */
bybit_err bybit_affiliate_affiliate_sub_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get LP Order List. POST /v5/alpha/lp/order-list. Auth: private. Required: none. */
bybit_err bybit_alpha_lp_order_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get LP Pay Token List. POST /v5/alpha/lp/pay-token-list. Auth: private. Required: none. */
bybit_err bybit_alpha_lp_pay_token_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get LP Pay Token Price. POST /v5/alpha/lp/pay-token-price. Auth: private. Required: tokenCode. */
bybit_err bybit_alpha_lp_pay_token_price(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get LP Pool Info. POST /v5/alpha/lp/pool-info. Auth: private. Required: poolAddress. */
bybit_err bybit_alpha_lp_pool_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get LP Pool List. POST /v5/alpha/lp/pool-list. Auth: private. Required: none. */
bybit_err bybit_alpha_lp_pool_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get LP Position List. POST /v5/alpha/lp/position-list. Auth: private. Required: none. */
bybit_err bybit_alpha_lp_position_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Execute LP Redeem. POST /v5/alpha/lp/redeem. Auth: private. Required: positionId, poolAddress, dercRatio. */
bybit_err bybit_alpha_lp_redeem(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Execute LP Stake. POST /v5/alpha/lp/stake. Auth: private. Required: positionId, poolAddress, payTokenAmount, payTokenCode. */
bybit_err bybit_alpha_lp_stake(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Execute Buy. POST /v5/alpha/prediction/buy. Auth: private. Required: tokenId, amount, payTokenCode, orderType, slippage, eventId. */
bybit_err bybit_alpha_prediction_buy(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Engine Status. GET /v5/alpha/prediction/engine-status. Auth: private. Required: none. */
bybit_err bybit_alpha_prediction_engine_status(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Event Detail. POST /v5/alpha/prediction/event-detail. Auth: private. Required: none. */
bybit_err bybit_alpha_prediction_event_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Order Book. POST /v5/alpha/prediction/order-book. Auth: private. Required: tokenIds. */
bybit_err bybit_alpha_prediction_order_book(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Order Estimate. POST /v5/alpha/prediction/order-estimate. Auth: private. Required: tokenId, side, eventId, amount, orderType. */
bybit_err bybit_alpha_prediction_order_estimate(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Order List. POST /v5/alpha/prediction/order-list. Auth: private. Required: none. */
bybit_err bybit_alpha_prediction_order_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Payment Token List. GET /v5/alpha/prediction/pay-token-list. Auth: private. Required: none. */
bybit_err bybit_alpha_prediction_pay_token_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Portfolio Summary. POST /v5/alpha/prediction/portfolio-summary. Auth: private. Required: none. */
bybit_err bybit_alpha_prediction_portfolio_summary(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Position History. POST /v5/alpha/prediction/position-history. Auth: private. Required: none. */
bybit_err bybit_alpha_prediction_position_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Position List. POST /v5/alpha/prediction/position-list. Auth: private. Required: none. */
bybit_err bybit_alpha_prediction_position_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Price History. POST /v5/alpha/prediction/price-history. Auth: private. Required: tokenId, interval. */
bybit_err bybit_alpha_prediction_price_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Execute Sell. POST /v5/alpha/prediction/sell. Auth: private. Required: tokenId, size, orderType, slippage, eventId. */
bybit_err bybit_alpha_prediction_sell(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Side Market List. POST /v5/alpha/prediction/side-market-list. Auth: private. Required: eventId. */
bybit_err bybit_alpha_prediction_side_market_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Sports Group Stage Detail. POST /v5/alpha/prediction/sports/group-stage-detail. Auth: private. Required: eventType. */
bybit_err bybit_alpha_prediction_sports_group_stage_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Sports Match List. POST /v5/alpha/prediction/sports/match-list. Auth: private. Required: eventType. */
bybit_err bybit_alpha_prediction_sports_match_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Sports Timeline Stages. GET /v5/alpha/prediction/sports/timeline-stages. Auth: private. Required: eventType. */
bybit_err bybit_alpha_prediction_sports_timeline_stages(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Token Price. POST /v5/alpha/prediction/token-price. Auth: private. Required: tokenIds. */
bybit_err bybit_alpha_prediction_token_price(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Asset Detail. POST /v5/alpha/trade/asset-detail. Auth: private. Required: chainCode, tokenAddress. */
bybit_err bybit_alpha_trade_asset_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Asset List. POST /v5/alpha/trade/asset-list. Auth: private. Required: none. */
bybit_err bybit_alpha_trade_asset_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Token Details. POST /v5/alpha/trade/biz-token-details. Auth: private. Required: chainCode, tokenAddress. */
bybit_err bybit_alpha_trade_biz_token_details(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Biz Token List. POST /v5/alpha/trade/biz-token-list. Auth: private. Required: none. */
bybit_err bybit_alpha_trade_biz_token_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Token Price List. POST /v5/alpha/trade/biz-token-price-list. Auth: private. Required: tokenAddressInfo. */
bybit_err bybit_alpha_trade_biz_token_price_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Order List. POST /v5/alpha/trade/order-list. Auth: private. Required: limit, pageIndex. */
bybit_err bybit_alpha_trade_order_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Payment Token List. POST /v5/alpha/trade/pay-token-list. Auth: private. Required: chainCode, tokenAddress. */
bybit_err bybit_alpha_trade_pay_token_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Execute Purchase. POST /v5/alpha/trade/purchase. Auth: private. Required: fromTokenCode, fromTokenAmount, toTokenCode, slippage, quoteData, gas, quoteMode, correctingCode. */
bybit_err bybit_alpha_trade_purchase(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Trade Quote. POST /v5/alpha/trade/quote. Auth: private. Required: tradeType, fromTokenCode, fromTokenAmount, toTokenCode. */
bybit_err bybit_alpha_trade_quote(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Execute Redeem. POST /v5/alpha/trade/redeem. Auth: private. Required: fromTokenCode, fromTokenAmount, toTokenCode, slippage, quoteData, gas, quoteMode, correctingCode. */
bybit_err bybit_alpha_trade_redeem(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Announcement. GET /v5/announcements/index. Auth: public. Required: locale. */
bybit_err bybit_announcements_index(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Rate Limit. GET /v5/apilimit/query. Auth: private. Required: uids. */
bybit_err bybit_apilimit_query(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get All Rate Limits. GET /v5/apilimit/query-all. Auth: private. Required: none. */
bybit_err bybit_apilimit_query_all(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Rate Limit Cap. GET /v5/apilimit/query-cap. Auth: private. Required: none. */
bybit_err bybit_apilimit_query_cap(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Set Rate Limit. POST /v5/apilimit/set. Auth: private. Required: list. */
bybit_err bybit_apilimit_set(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Asset Overview. GET /v5/asset/asset-overview. Auth: private. Required: none. */
bybit_err bybit_asset_asset_overview(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Coin Greeks. GET /v5/asset/coin-greeks. Auth: private. Required: none. */
bybit_err bybit_asset_coin_greeks(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Coin Info. GET /v5/asset/coin/query-info. Auth: private. Required: none. */
bybit_err bybit_asset_coin_query_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Request a Quote. POST /v5/asset/covert/get-quote. Auth: private. Required: accountType, fromCoinList, toCoin. */
bybit_err bybit_asset_covert_get_quote(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Confirm a Quote. POST /v5/asset/covert/small-balance-execute. Auth: private. Required: quoteId. */
bybit_err bybit_asset_covert_small_balance_execute(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Exchange History. GET /v5/asset/covert/small-balance-history. Auth: private. Required: none. */
bybit_err bybit_asset_covert_small_balance_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Small Balance Coins. GET /v5/asset/covert/small-balance-list. Auth: private. Required: accountType. */
bybit_err bybit_asset_covert_small_balance_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Delivery Record. GET /v5/asset/delivery-record. Auth: private. Required: category. */
bybit_err bybit_asset_delivery_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Set Deposit Account. POST /v5/asset/deposit/deposit-to-account. Auth: private. Required: accountType. */
bybit_err bybit_asset_deposit_deposit_to_account(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Master Deposit Address. GET /v5/asset/deposit/query-address. Auth: private. Required: coin. */
bybit_err bybit_asset_deposit_query_address(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Internal Deposit Records (off-chain). GET /v5/asset/deposit/query-internal-record. Auth: private. Required: none. */
bybit_err bybit_asset_deposit_query_internal_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Deposit Records (on-chain). GET /v5/asset/deposit/query-record. Auth: private. Required: none. */
bybit_err bybit_asset_deposit_query_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Sub Deposit Address. GET /v5/asset/deposit/query-sub-member-address. Auth: private. Required: coin, chainType, subMemberId. */
bybit_err bybit_asset_deposit_query_sub_member_address(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Sub Deposit Records (on-chain). GET /v5/asset/deposit/query-sub-member-record. Auth: private. Required: subMemberId. */
bybit_err bybit_asset_deposit_query_sub_member_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Confirm a Quote. POST /v5/asset/exchange/convert-execute. Auth: private. Required: quoteTxId. */
bybit_err bybit_asset_exchange_convert_execute(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Convert Status. GET /v5/asset/exchange/convert-result-query. Auth: private. Required: quoteTxId, accountType. */
bybit_err bybit_asset_exchange_convert_result_query(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Coin Exchange Records. GET /v5/asset/exchange/order-record. Auth: private. Required: none. */
bybit_err bybit_asset_exchange_order_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Convert Coin List. GET /v5/asset/exchange/query-coin-list. Auth: private. Required: accountType. */
bybit_err bybit_asset_exchange_query_coin_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Convert History. GET /v5/asset/exchange/query-convert-history. Auth: private. Required: none. */
bybit_err bybit_asset_exchange_query_convert_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Request a Quote. POST /v5/asset/exchange/quote-apply. Auth: private. Required: accountType, fromCoin, toCoin, requestCoin, requestAmount. */
bybit_err bybit_asset_exchange_quote_apply(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Funding Account Transaction History. GET /v5/asset/fundinghistory. Auth: private. Required: none. */
bybit_err bybit_asset_fundinghistory(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Portfolio Margin Info. GET /v5/asset/portfolio-margin. Auth: private. Required: none. */
bybit_err bybit_asset_portfolio_margin(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get USDC Session Settlement. GET /v5/asset/settlement-record. Auth: private. Required: category. */
bybit_err bybit_asset_settlement_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Total Members Assets. GET /v5/asset/total-members-assets. Auth: private. Required: none. */
bybit_err bybit_asset_total_members_assets(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Create Internal Transfer. POST /v5/asset/transfer/inter-transfer. Auth: private. Required: transferId, coin, amount, fromAccountType, toAccountType. */
bybit_err bybit_asset_transfer_inter_transfer(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Single Coin Balance. GET /v5/asset/transfer/query-account-coin-balance. Auth: private. Required: accountType, coin. */
bybit_err bybit_asset_transfer_query_account_coin_balance(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get All Coins Balance. GET /v5/asset/transfer/query-account-coins-balance. Auth: private. Required: accountType. */
bybit_err bybit_asset_transfer_query_account_coins_balance(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Internal Transfer Records. GET /v5/asset/transfer/query-inter-transfer-list. Auth: private. Required: none. */
bybit_err bybit_asset_transfer_query_inter_transfer_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Sub UID. GET /v5/asset/transfer/query-sub-member-list. Auth: private. Required: none. */
bybit_err bybit_asset_transfer_query_sub_member_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Transferable Coin. GET /v5/asset/transfer/query-transfer-coin-list. Auth: private. Required: fromAccountType, toAccountType. */
bybit_err bybit_asset_transfer_query_transfer_coin_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Universal Transfer Records. GET /v5/asset/transfer/query-universal-transfer-list. Auth: private. Required: none. */
bybit_err bybit_asset_transfer_query_universal_transfer_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Create Universal Transfer. POST /v5/asset/transfer/universal-transfer. Auth: private. Required: transferId, coin, amount, fromMemberId, toMemberId, fromAccountType, toAccountType. */
bybit_err bybit_asset_transfer_universal_transfer(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Submit Deposit Originator Info. POST /v5/asset/travel-rule/deposit/submit. Auth: private. Required: depositId, questionnaire. */
bybit_err bybit_asset_travel_rule_deposit_submit(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Cancel Withdrawal. POST /v5/asset/withdraw/cancel. Auth: private. Required: id. */
bybit_err bybit_asset_withdraw_cancel(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Withdraw. POST /v5/asset/withdraw/create. Auth: private. Required: coin, address, amount, timestamp, accountType. */
bybit_err bybit_asset_withdraw_create(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Withdrawal Address List. GET /v5/asset/withdraw/query-address. Auth: private. Required: none. */
bybit_err bybit_asset_withdraw_query_address(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Withdrawal Records. GET /v5/asset/withdraw/query-record. Auth: private. Required: none. */
bybit_err bybit_asset_withdraw_query_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get available VASPs. GET /v5/asset/withdraw/vasp/list. Auth: private. Required: none. */
bybit_err bybit_asset_withdraw_vasp_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Withdrawable Amount. GET /v5/asset/withdraw/withdrawable-amount. Auth: private. Required: coin. */
bybit_err bybit_asset_withdraw_withdrawable_amount(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Account Info. GET /v5/broker/account-info. Auth: private. Required: none. */
bybit_err bybit_broker_account_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get All Rate Limits. GET /v5/broker/apilimit/query-all. Auth: private. Required: none. */
bybit_err bybit_broker_apilimit_query_all(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Rate Limit Cap. GET /v5/broker/apilimit/query-cap. Auth: private. Required: none. */
bybit_err bybit_broker_apilimit_query_cap(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Set Rate Limit. POST /v5/broker/apilimit/set. Auth: private. Required: list. */
bybit_err bybit_broker_apilimit_set(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Sub Account Deposit Records. GET /v5/broker/asset/query-sub-member-deposit-record. Auth: private. Required: none. */
bybit_err bybit_broker_asset_query_sub_member_deposit_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Issue Voucher. POST /v5/broker/award/distribute-award. Auth: private. Required: accountId, awardId, specCode, amount, brokerId. */
bybit_err bybit_broker_award_distribute_award(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Issued Voucher. POST /v5/broker/award/distribution-record. Auth: private. Required: accountId, awardId, specCode. */
bybit_err bybit_broker_award_distribution_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Voucher Spec. POST /v5/broker/award/info. Auth: private. Required: id. */
bybit_err bybit_broker_award_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Earning. GET /v5/broker/earnings-info. Auth: private. Required: none. */
bybit_err bybit_broker_earnings_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Broker IP Change Log. GET /v5/broker/ip/changelog. Auth: private. Required: none. */
bybit_err bybit_broker_ip_changelog(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Broker Whitelist IP. GET /v5/broker/whitelist/ip. Auth: public. Required: none. */
bybit_err bybit_broker_whitelist_ip(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Query Mall Item List. POST /v5/card/reward/mall/item/list. Auth: private. Required: none. */
bybit_err bybit_card_reward_mall_item_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Query Cashback Detail. POST /v5/card/reward/point/cashback/detail. Auth: private. Required: bizTxnId. */
bybit_err bybit_card_reward_point_cashback_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Query Point Balance. POST /v5/card/reward/points/balance. Auth: private. Required: none. */
bybit_err bybit_card_reward_points_balance(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Query Point Records. POST /v5/card/reward/points/records. Auth: private. Required: none. */
bybit_err bybit_card_reward_points_records(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Query Tier Info. POST /v5/card/reward/points/tier. Auth: private. Required: none. */
bybit_err bybit_card_reward_points_tier(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Query Asset Records. POST /v5/card/transaction/query-asset-records. Auth: private. Required: none. */
bybit_err bybit_card_transaction_query_asset_records(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Commit Appeal. POST /v5/compliance/appeal/commit. Auth: private. Required: appealId, itemsData. */
bybit_err bybit_compliance_appeal_commit(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Appeal Detail. GET /v5/compliance/appeal/detail. Auth: private. Required: appealId. */
bybit_err bybit_compliance_appeal_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Appeal List. GET /v5/compliance/appeal/list. Auth: private. Required: none. */
bybit_err bybit_compliance_appeal_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Adjust Collateral Amount. POST /v5/crypto-loan-common/adjust-ltv. Auth: private. Required: currency, amount, direction. */
bybit_err bybit_crypto_loan_common_adjust_ltv(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Collateral Adjustment History. GET /v5/crypto-loan-common/adjustment-history. Auth: private. Required: none. */
bybit_err bybit_crypto_loan_common_adjustment_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Collateral Coins. GET /v5/crypto-loan-common/collateral-data. Auth: public. Required: none. */
bybit_err bybit_crypto_loan_common_collateral_data(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Borrowable Coins. GET /v5/crypto-loan-common/loanable-data. Auth: public. Required: none. */
bybit_err bybit_crypto_loan_common_loanable_data(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Max. Allowed Collateral Reduction Amount. GET /v5/crypto-loan-common/max-collateral-amount. Auth: private. Required: currency. */
bybit_err bybit_crypto_loan_common_max_collateral_amount(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Obtain Max Loan Amount. POST /v5/crypto-loan-common/max-loan. Auth: private. Required: currency. */
bybit_err bybit_crypto_loan_common_max_loan(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Crypto Loan Position. GET /v5/crypto-loan-common/position. Auth: private. Required: none. */
bybit_err bybit_crypto_loan_common_position(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Available Inventory. GET /v5/crypto-loan-fixed/available-inventory. Auth: private. Required: currency, term, annualRate. */
bybit_err bybit_crypto_loan_fixed_available_inventory(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Create Borrow Order. POST /v5/crypto-loan-fixed/borrow. Auth: private. Required: orderCurrency, orderAmount, annualRate, term. */
bybit_err bybit_crypto_loan_fixed_borrow(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Borrow Contract Info. GET /v5/crypto-loan-fixed/borrow-contract-info. Auth: private. Required: none. */
bybit_err bybit_crypto_loan_fixed_borrow_contract_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Cancel Borrow Order. POST /v5/crypto-loan-fixed/borrow-order-cancel. Auth: private. Required: orderId. */
bybit_err bybit_crypto_loan_fixed_borrow_order_cancel(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Borrow Order Info. GET /v5/crypto-loan-fixed/borrow-order-info. Auth: private. Required: none. */
bybit_err bybit_crypto_loan_fixed_borrow_order_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Borrowing Market. GET /v5/crypto-loan-fixed/borrow-order-quote. Auth: private. Required: orderCurrency, orderBy. */
bybit_err bybit_crypto_loan_fixed_borrow_order_quote(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Repay. POST /v5/crypto-loan-fixed/fully-repay. Auth: private. Required: none. */
bybit_err bybit_crypto_loan_fixed_fully_repay(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Renew Borrow Order. POST /v5/crypto-loan-fixed/renew. Auth: private. Required: loanId. */
bybit_err bybit_crypto_loan_fixed_renew(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Renew Order Info. GET /v5/crypto-loan-fixed/renew-info. Auth: private. Required: none. */
bybit_err bybit_crypto_loan_fixed_renew_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Collateral Repayment. POST /v5/crypto-loan-fixed/repay-collateral. Auth: private. Required: loanCurrency, collateralCoin, amount. */
bybit_err bybit_crypto_loan_fixed_repay_collateral(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Repayment History. GET /v5/crypto-loan-fixed/repayment-history. Auth: private. Required: none. */
bybit_err bybit_crypto_loan_fixed_repayment_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Create Supply Order. POST /v5/crypto-loan-fixed/supply. Auth: private. Required: orderCurrency, orderAmount, annualRate, term. */
bybit_err bybit_crypto_loan_fixed_supply(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Supply Contract Info. GET /v5/crypto-loan-fixed/supply-contract-info. Auth: private. Required: none. */
bybit_err bybit_crypto_loan_fixed_supply_contract_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Cancel Supply Order. POST /v5/crypto-loan-fixed/supply-order-cancel. Auth: private. Required: orderId. */
bybit_err bybit_crypto_loan_fixed_supply_order_cancel(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Supply Order Info. GET /v5/crypto-loan-fixed/supply-order-info. Auth: private. Required: none. */
bybit_err bybit_crypto_loan_fixed_supply_order_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Lending Market. GET /v5/crypto-loan-fixed/supply-order-quote. Auth: private. Required: orderCurrency, orderBy. */
bybit_err bybit_crypto_loan_fixed_supply_order_quote(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Available Inventory. GET /v5/crypto-loan-flexible/available-inventory. Auth: private. Required: currency. */
bybit_err bybit_crypto_loan_flexible_available_inventory(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Borrow. POST /v5/crypto-loan-flexible/borrow. Auth: private. Required: loanCurrency, loanAmount. */
bybit_err bybit_crypto_loan_flexible_borrow(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Borrowing History. GET /v5/crypto-loan-flexible/borrow-history. Auth: private. Required: none. */
bybit_err bybit_crypto_loan_flexible_borrow_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Flexible Loans. GET /v5/crypto-loan-flexible/ongoing-coin. Auth: private. Required: none. */
bybit_err bybit_crypto_loan_flexible_ongoing_coin(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Repay. POST /v5/crypto-loan-flexible/repay. Auth: private. Required: loanCurrency, amount. */
bybit_err bybit_crypto_loan_flexible_repay(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Collateral Repayment. POST /v5/crypto-loan-flexible/repay-collateral. Auth: private. Required: loanCurrency, collateralCoin, amount. */
bybit_err bybit_crypto_loan_flexible_repay_collateral(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Repayment History. GET /v5/crypto-loan-flexible/repayment-history. Auth: private. Required: none. */
bybit_err bybit_crypto_loan_flexible_repayment_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Adjust Collateral Amount. POST /v5/crypto-loan/adjust-ltv. Auth: private. Required: orderId, amount, direction. */
bybit_err bybit_crypto_loan_adjust_ltv(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Loan LTV Adjustment History. GET /v5/crypto-loan/adjustment-history. Auth: private. Required: none. */
bybit_err bybit_crypto_loan_adjustment_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Completed Loan History. GET /v5/crypto-loan/borrow-history. Auth: private. Required: none. */
bybit_err bybit_crypto_loan_borrow_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Account Borrowable/Collateralizable Limit. GET /v5/crypto-loan/borrowable-collateralisable-number. Auth: private. Required: loanCurrency, collateralCurrency. */
bybit_err bybit_crypto_loan_borrowable_collateralisable_number(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Collateral Coins. GET /v5/crypto-loan/collateral-data. Auth: public. Required: none. */
bybit_err bybit_crypto_loan_collateral_data(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Borrowable Coins. GET /v5/crypto-loan/loanable-data. Auth: public. Required: none. */
bybit_err bybit_crypto_loan_loanable_data(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Max. Allowed Collateral Reduction Amount. GET /v5/crypto-loan/max-collateral-amount. Auth: private. Required: orderId. */
bybit_err bybit_crypto_loan_max_collateral_amount(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Unpaid Loans. GET /v5/crypto-loan/ongoing-orders. Auth: private. Required: none. */
bybit_err bybit_crypto_loan_ongoing_orders(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Repay. POST /v5/crypto-loan/repay. Auth: private. Required: orderId, amount. */
bybit_err bybit_crypto_loan_repay(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Loan Repayment History. GET /v5/crypto-loan/repayment-history. Auth: private. Required: none. */
bybit_err bybit_crypto_loan_repayment_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Close DCA Bot. POST /v5/dca/close-bot. Auth: private. Required: bot_id, close_mode. */
bybit_err bybit_dca_close_bot(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Create DCA Bot. POST /v5/dca/create-bot. Auth: private. Required: parameters. */
bybit_err bybit_dca_create_bot(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Custom Product Quote. GET /v5/earn/advance/double-win-leverage. Auth: private. Required: productId, initialPrice, lowerPrice, upperPrice. */
bybit_err bybit_earn_advance_double_win_leverage(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Redeem Estimated Amount. GET /v5/earn/advance/get-redeem-est-amount-list. Auth: private. Required: category, positionIds. */
bybit_err bybit_earn_advance_get_redeem_est_amount_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Order Info. GET /v5/earn/advance/order. Auth: private. Required: category. */
bybit_err bybit_earn_advance_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Place Order. POST /v5/earn/advance/place-order. Auth: private. Required: category, productId, orderType, amount, accountType, coin, orderLinkId, dualAssetsExtra. */
bybit_err bybit_earn_advance_place_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Position Info. GET /v5/earn/advance/position. Auth: private. Required: category. */
bybit_err bybit_earn_advance_position(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Product Info. GET /v5/earn/advance/product. Auth: public. Required: category. */
bybit_err bybit_earn_advance_product(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Product Quote. GET /v5/earn/advance/product-extra-info. Auth: public. Required: productId, category. */
bybit_err bybit_earn_advance_product_extra_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get APR History. GET /v5/earn/apr-history. Auth: public. Required: category, productId. */
bybit_err bybit_earn_apr_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Coupon List. GET /v5/earn/coupons. Auth: private. Required: category. */
bybit_err bybit_earn_coupons(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Order List. GET /v5/earn/fixed-term/order. Auth: private. Required: none. */
bybit_err bybit_earn_fixed_term_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Place Order. POST /v5/earn/fixed-term/place-order. Auth: private. Required: productId, category, coin, amount, accountType, orderLinkId. */
bybit_err bybit_earn_fixed_term_place_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Position Info. GET /v5/earn/fixed-term/position. Auth: private. Required: none. */
bybit_err bybit_earn_fixed_term_position(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Set Auto-Invest. POST /v5/earn/fixed-term/position/auto-invest. Auth: private. Required: productId, category, positionId, status. */
bybit_err bybit_earn_fixed_term_position_auto_invest(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Product Info. GET /v5/earn/fixed-term/product. Auth: private. Required: none. */
bybit_err bybit_earn_fixed_term_product(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Redeem. POST /v5/earn/fixed-term/redeem. Auth: private. Required: productId, category, positionId. */
bybit_err bybit_earn_fixed_term_redeem(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get/Set Auto Savings Settings. GET /v5/earn/flexible-saving/auto-savings. Auth: private. Required: none. */
bybit_err bybit_earn_flexible_saving_auto_savings_get(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get/Set Auto Savings Settings. POST /v5/earn/flexible-saving/auto-savings. Auth: private. Required: none. */
bybit_err bybit_earn_flexible_saving_auto_savings_post(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Airdrop Products. GET /v5/earn/hold-to-earn/product. Auth: public. Required: none. */
bybit_err bybit_earn_hold_to_earn_product(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Airdrop Daily PnL Records. GET /v5/earn/hold-to-earn/yield-history. Auth: private. Required: limit. */
bybit_err bybit_earn_hold_to_earn_yield_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Hourly Yield History. GET /v5/earn/hourly-yield. Auth: private. Required: category. */
bybit_err bybit_earn_hourly_yield(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Add Liquidity. POST /v5/earn/liquidity-mining/add-liquidity. Auth: private. Required: productId, orderLinkId. */
bybit_err bybit_earn_liquidity_mining_add_liquidity(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Add Margin. POST /v5/earn/liquidity-mining/add-margin. Auth: private. Required: productId, orderLinkId, positionId, amount, quoteAccountType. */
bybit_err bybit_earn_liquidity_mining_add_margin(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Claim Interest. POST /v5/earn/liquidity-mining/claim-interest. Auth: private. Required: productId. */
bybit_err bybit_earn_liquidity_mining_claim_interest(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Liquidation Records. GET /v5/earn/liquidity-mining/liquidation-records. Auth: private. Required: none. */
bybit_err bybit_earn_liquidity_mining_liquidation_records(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Order Info. GET /v5/earn/liquidity-mining/order. Auth: private. Required: none. */
bybit_err bybit_earn_liquidity_mining_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Position Info. GET /v5/earn/liquidity-mining/position. Auth: private. Required: none. */
bybit_err bybit_earn_liquidity_mining_position(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Product Info. GET /v5/earn/liquidity-mining/product. Auth: public. Required: none. */
bybit_err bybit_earn_liquidity_mining_product(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Reinvest. POST /v5/earn/liquidity-mining/reinvest. Auth: private. Required: productId, orderLinkId, positionId. */
bybit_err bybit_earn_liquidity_mining_reinvest(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Remove Liquidity. POST /v5/earn/liquidity-mining/remove-liquidity. Auth: private. Required: productId, orderLinkId, positionId. */
bybit_err bybit_earn_liquidity_mining_remove_liquidity(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Yield Records. GET /v5/earn/liquidity-mining/yield-records. Auth: private. Required: none. */
bybit_err bybit_earn_liquidity_mining_yield_records(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Stake/Redeem Order History. GET /v5/earn/order. Auth: private. Required: category. */
bybit_err bybit_earn_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Stake / Redeem. POST /v5/earn/place-order. Auth: private. Required: category, orderType, accountType, amount, coin, productId, orderLinkId. */
bybit_err bybit_earn_place_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Staked Position. GET /v5/earn/position. Auth: private. Required: category. */
bybit_err bybit_earn_position(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Modify Position. POST /v5/earn/position/modify. Auth: private. Required: category, productId, positionId, autoReinvest. */
bybit_err bybit_earn_position_modify(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Product Info. GET /v5/earn/product. Auth: public. Required: category. */
bybit_err bybit_earn_product(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get All Funds. GET /v5/earn/pwm/asset-manager/all-funds. Auth: private. Required: none. */
bybit_err bybit_earn_pwm_asset_manager_all_funds(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get All Fund Orders. GET /v5/earn/pwm/asset-manager/all-order. Auth: private. Required: none. */
bybit_err bybit_earn_pwm_asset_manager_all_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Create Fund (Pending Subscription). POST /v5/earn/pwm/asset-manager/create-fund. Auth: private. Required: fundName, coin, profitShareRate, managementFeeRate, reqLinkId. */
bybit_err bybit_earn_pwm_asset_manager_create_fund(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Create Investment Plan. POST /v5/earn/pwm/asset-manager/create-investment-plan. Auth: private. Required: accountUid, planName, planType, investmentDistribution, reqLinkId. */
bybit_err bybit_earn_pwm_asset_manager_create_investment_plan(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Create Fund Sub-Account. POST /v5/earn/pwm/asset-manager/create-sub-account. Auth: private. Required: fundId, reqLinkId. */
bybit_err bybit_earn_pwm_asset_manager_create_sub_account(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Investment Plans. GET /v5/earn/pwm/asset-manager/get-investment-plan. Auth: private. Required: none. */
bybit_err bybit_earn_pwm_asset_manager_get_investment_plan(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Manage Investment Plan. POST /v5/earn/pwm/asset-manager/manage-investment-plan. Auth: private. Required: planId, reqLinkId. */
bybit_err bybit_earn_pwm_asset_manager_manage_investment_plan(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Manage Order. POST /v5/earn/pwm/asset-manager/manage-order. Auth: private. Required: orderId, action, reqLinkId. */
bybit_err bybit_earn_pwm_asset_manager_manage_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Settle Fund Profit. POST /v5/earn/pwm/asset-manager/settle-profit. Auth: private. Required: fundId, reqLinkId. */
bybit_err bybit_earn_pwm_asset_manager_settle_profit(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Create Customize Investment Plan. POST /v5/earn/pwm/customize-plan/create. Auth: private. Required: products. */
bybit_err bybit_earn_pwm_customize_plan_create(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Subscribable Product Info. GET /v5/earn/pwm/customize-plan/product. Auth: public. Required: none. */
bybit_err bybit_earn_pwm_customize_plan_product(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Fund Transfer Between Sub-Accounts. POST /v5/earn/pwm/fund-transfer. Auth: private. Required: transferId, fromUserId, toUserId, amount, coin. */
bybit_err bybit_earn_pwm_fund_transfer(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get All Investment Plans. GET /v5/earn/pwm/investment-plan/all. Auth: private. Required: none. */
bybit_err bybit_earn_pwm_investment_plan_all(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Asset Trend. GET /v5/earn/pwm/investment-plan/asset-trend. Auth: private. Required: planId. */
bybit_err bybit_earn_pwm_investment_plan_asset_trend(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Claim Withdrawable Funds. POST /v5/earn/pwm/investment-plan/claim. Auth: private. Required: planId, orderLinkId. */
bybit_err bybit_earn_pwm_investment_plan_claim(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Investment Plan Detail. GET /v5/earn/pwm/investment-plan/detail. Auth: private. Required: planId. */
bybit_err bybit_earn_pwm_investment_plan_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Fund Historical NAV. GET /v5/earn/pwm/investment-plan/fund-nav. Auth: private. Required: fundId. */
bybit_err bybit_earn_pwm_investment_plan_fund_nav(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Invest More. POST /v5/earn/pwm/investment-plan/invest-more. Auth: private. Required: planId, category, productId, amount, orderLinkId. */
bybit_err bybit_earn_pwm_investment_plan_invest_more(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Pending Investment Plan Detail. GET /v5/earn/pwm/investment-plan/new-plan. Auth: private. Required: planId. */
bybit_err bybit_earn_pwm_investment_plan_new_plan(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Investment Plan Orders. GET /v5/earn/pwm/investment-plan/order. Auth: private. Required: none. */
bybit_err bybit_earn_pwm_investment_plan_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Redeem. POST /v5/earn/pwm/investment-plan/redeem. Auth: private. Required: planId, category, productId, orderLinkId. */
bybit_err bybit_earn_pwm_investment_plan_redeem(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Subscribe Investment Plan. POST /v5/earn/pwm/investment-plan/subscribe. Auth: private. Required: planId, orderLinkId. */
bybit_err bybit_earn_pwm_investment_plan_subscribe(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Fund Transfer Records. GET /v5/earn/pwm/query-fund-transfer-result. Auth: private. Required: none. */
bybit_err bybit_earn_pwm_query_fund_transfer_result(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get NAV Chart. GET /v5/earn/rwa/nav-chart. Auth: public. Required: productId. */
bybit_err bybit_earn_rwa_nav_chart(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Order List. GET /v5/earn/rwa/order. Auth: private. Required: none. */
bybit_err bybit_earn_rwa_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Place Order. POST /v5/earn/rwa/place-order. Auth: private. Required: productId, orderType, coin, orderLinkId. */
bybit_err bybit_earn_rwa_place_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Position List. GET /v5/earn/rwa/position. Auth: private. Required: none. */
bybit_err bybit_earn_rwa_position(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Product List. GET /v5/earn/rwa/product. Auth: public. Required: none. */
bybit_err bybit_earn_rwa_product(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get History APR. GET /v5/earn/token/history-apr. Auth: public. Required: coin, range. */
bybit_err bybit_earn_token_history_apr(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Hourly Yield Records. GET /v5/earn/token/hourly-yield. Auth: private. Required: coin. */
bybit_err bybit_earn_token_hourly_yield(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Order List. GET /v5/earn/token/order. Auth: private. Required: coin. */
bybit_err bybit_earn_token_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Place Order. POST /v5/earn/token/place-order. Auth: private. Required: coin, orderLinkId, orderType, amount, accountType. */
bybit_err bybit_earn_token_place_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Position Info. GET /v5/earn/token/position. Auth: private. Required: coin. */
bybit_err bybit_earn_token_position(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Product Info. GET /v5/earn/token/product. Auth: private. Required: coin. */
bybit_err bybit_earn_token_product(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Daily Yield Records. GET /v5/earn/token/yield. Auth: private. Required: coin. */
bybit_err bybit_earn_token_yield(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Yield History. GET /v5/earn/yield. Auth: private. Required: category. */
bybit_err bybit_earn_yield(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Cancel Quote. POST /v5/event/cancel. Auth: private. Required: none. */
bybit_err bybit_event_cancel(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Cancel All Quotes. POST /v5/event/cancel-all. Auth: private. Required: symbol. */
bybit_err bybit_event_cancel_all(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Instrument Info. GET /v5/event/instruments-info. Auth: public. Required: none. */
bybit_err bybit_event_instruments_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Event Contract Order History. GET /v5/event/order-list. Auth: private. Required: none. */
bybit_err bybit_event_order_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Event Contract Active Orders. GET /v5/event/order-realtime. Auth: private. Required: none. */
bybit_err bybit_event_order_realtime(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Orderbook. GET /v5/event/orderbook. Auth: public. Required: symbol. */
bybit_err bybit_event_orderbook(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Event Contract Position Info. GET /v5/event/positions. Auth: private. Required: none. */
bybit_err bybit_event_positions(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Submit Quote. POST /v5/event/quotes. Auth: private. Required: symbol, orderLinkId, grossPayoutRatio, amount. */
bybit_err bybit_event_quotes(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Event Contract Settlement Records. GET /v5/event/settlements. Auth: private. Required: symbol. */
bybit_err bybit_event_settlements(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Event Contract Trade History. GET /v5/event/trades. Auth: private. Required: symbol. */
bybit_err bybit_event_trades(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Trade History. GET /v5/execution/list. Auth: private. Required: category. */
bybit_err bybit_execution_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Close Bot. POST /v5/fcombobot/close. Auth: private. Required: bot_id. */
bybit_err bybit_fcombobot_close(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Create Bot. POST /v5/fcombobot/create. Auth: private. Required: leverage, init_margin, adjust_position_mode, symbol_settings. */
bybit_err bybit_fcombobot_create(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Bot Detail. POST /v5/fcombobot/detail. Auth: private. Required: bot_id. */
bybit_err bybit_fcombobot_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Bot Parameter Limit. POST /v5/fcombobot/getlimit. Auth: private. Required: leverage, init_margin, adjust_position_mode, symbol_settings. */
bybit_err bybit_fcombobot_getlimit(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Close Grid Bot. POST /v5/fgridbot/close. Auth: private. Required: bot_id. */
bybit_err bybit_fgridbot_close(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Create Grid Bot. POST /v5/fgridbot/create. Auth: private. Required: symbol, grid_mode, min_price, max_price, cell_number, leverage, grid_type, total_investment. */
bybit_err bybit_fgridbot_create(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Grid Bot Detail. POST /v5/fgridbot/detail. Auth: private. Required: bot_id. */
bybit_err bybit_fgridbot_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Validate Grid Input. POST /v5/fgridbot/validate. Auth: private. Required: symbol, cell_number, min_price, max_price, leverage, grid_type, grid_mode. */
bybit_err bybit_fgridbot_validate(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Batch Request Export Reports. POST /v5/fht/compliance/tax/private/batch_create. Auth: private. Required: startTime, endTime, items. */
bybit_err bybit_fht_compliance_tax_private_batch_create(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Batch Export Report Status. GET /v5/fht/compliance/tax/private/batch_query. Auth: private. Required: batchId. */
bybit_err bybit_fht_compliance_tax_private_batch_query(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Balance. GET /v5/fiat/balance-query. Auth: private. Required: none. */
bybit_err bybit_fiat_balance_query(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Trading Pair List. GET /v5/fiat/query-coin-list. Auth: private. Required: none. */
bybit_err bybit_fiat_query_coin_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Convert History. GET /v5/fiat/query-trade-history. Auth: private. Required: none. */
bybit_err bybit_fiat_query_trade_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Request a Quote. POST /v5/fiat/quote-apply. Auth: private. Required: fromCoin, fromCoinType, toCoin, toCoinType, requestAmount. */
bybit_err bybit_fiat_quote_apply(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Reference Price. GET /v5/fiat/reference-price. Auth: private. Required: symbol. */
bybit_err bybit_fiat_reference_price(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Confirm a Quote. POST /v5/fiat/trade-execute. Auth: private. Required: quoteTxId, subUserId. */
bybit_err bybit_fiat_trade_execute(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Convert Status. GET /v5/fiat/trade-query. Auth: private. Required: none. */
bybit_err bybit_fiat_trade_query(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get File Upload Sign. POST /v5/file/get-file-upload-sign. Auth: private. Required: fileType, fileMd5, fileLen, fileName, fileMimeType. */
bybit_err bybit_file_get_file_upload_sign(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Report File Upload. POST /v5/file/report-file-upload. Auth: private. Required: resourceId. */
bybit_err bybit_file_report_file_upload(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Close Martingale Bot. POST /v5/fmartingalebot/close. Auth: private. Required: bot_id. */
bybit_err bybit_fmartingalebot_close(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Create Martingale Bot. POST /v5/fmartingalebot/create. Auth: private. Required: symbol, martingale_mode, leverage, price_float_percent, add_position_percent, add_position_num, init_margin, round_tp_percent. */
bybit_err bybit_fmartingalebot_create(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Martingale Bot Detail. POST /v5/fmartingalebot/detail. Auth: private. Required: bot_id. */
bybit_err bybit_fmartingalebot_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Bot Parameter Limit. POST /v5/fmartingalebot/getlimit. Auth: private. Required: symbol, martingale_mode, leverage. */
bybit_err bybit_fmartingalebot_getlimit(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Close Grid Bot. POST /v5/grid/close-grid. Auth: private. Required: grid_id, close_mode. */
bybit_err bybit_grid_close_grid(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Create Grid Bot. POST /v5/grid/create-grid. Auth: private. Required: symbol, max_price, min_price, cell_number. */
bybit_err bybit_grid_create_grid(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Grid Bot Detail. POST /v5/grid/query-grid-detail. Auth: private. Required: grid_id. */
bybit_err bybit_grid_query_grid_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Validate Grid Input. POST /v5/grid/validate-input. Auth: public. Required: symbol, cell_number, min_price, max_price. */
bybit_err bybit_grid_validate_input(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Bind Or Unbind UID. POST /v5/ins-loan/association-uid. Auth: private. Required: uid, operate. */
bybit_err bybit_ins_loan_association_uid(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Coin Delta Amount. GET /v5/ins-loan/coin-delta-amount. Auth: private. Required: none. */
bybit_err bybit_ins_loan_coin_delta_amount(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Delay Liquidation Status. GET /v5/ins-loan/delay-liq-status. Auth: private. Required: none. */
bybit_err bybit_ins_loan_delay_liq_status(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Margin Coin Info. GET /v5/ins-loan/ensure-tokens-convert. Auth: private. Required: none. */
bybit_err bybit_ins_loan_ensure_tokens_convert(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Loan Orders. GET /v5/ins-loan/loan-order. Auth: private. Required: none. */
bybit_err bybit_ins_loan_loan_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get LTV. GET /v5/ins-loan/ltv-convert. Auth: private. Required: none. */
bybit_err bybit_ins_loan_ltv_convert(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Product Info. GET /v5/ins-loan/product-infos. Auth: private. Required: none. */
bybit_err bybit_ins_loan_product_infos(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Repayment Orders. GET /v5/ins-loan/repaid-history. Auth: private. Required: none. */
bybit_err bybit_ins_loan_repaid_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Repay. POST /v5/ins-loan/repay-loan. Auth: private. Required: token, quantity. */
bybit_err bybit_ins_loan_repay_loan(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Institution IP Change Log. GET /v5/ins/ip/changelog. Auth: private. Required: none. */
bybit_err bybit_ins_ip_changelog(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Institution Whitelist IP. GET /v5/ins/whitelist/ip. Auth: private. Required: none. */
bybit_err bybit_ins_whitelist_ip(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Long Short Ratio. GET /v5/market/account-ratio. Auth: public. Required: category, symbol, period. */
bybit_err bybit_market_account_ratio(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get ADL Alert. GET /v5/market/adlAlert. Auth: public. Required: none. */
bybit_err bybit_market_adlAlert(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Query Corporate Action. GET /v5/market/corporate-action. Auth: public. Required: none. */
bybit_err bybit_market_corporate_action(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Delivery Price. GET /v5/market/delivery-price. Auth: public. Required: category. */
bybit_err bybit_market_delivery_price(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Fee Group Structure. GET /v5/market/fee-group-info. Auth: public. Required: productType. */
bybit_err bybit_market_fee_group_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Full Depth Orderbook. GET /v5/market/full_orderbook. Auth: public. Required: category, symbol. */
bybit_err bybit_market_full_orderbook(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Funding Rate History. GET /v5/market/funding/history. Auth: public. Required: category, symbol. */
bybit_err bybit_market_funding_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Historical Volatility. GET /v5/market/historical-volatility. Auth: public. Required: category. */
bybit_err bybit_market_historical_volatility(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* TradFi Integration. GET /v5/market/index-price-components. Auth: public. Required: agree. */
bybit_err bybit_market_index_price_components(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Index Price Kline. GET /v5/market/index-price-kline. Auth: public. Required: symbol, interval. */
bybit_err bybit_market_index_price_kline(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Instrument Summary. GET /v5/market/instrument-summary. Auth: public. Required: category. */
bybit_err bybit_market_instrument_summary(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* TradFi Integration. GET /v5/market/instruments-info. Auth: public. Required: agree. */
bybit_err bybit_market_instruments_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Insurance Pool. GET /v5/market/insurance. Auth: public. Required: none. */
bybit_err bybit_market_insurance(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Kline. GET /v5/market/kline. Auth: public. Required: symbol, interval. */
bybit_err bybit_market_kline(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Mark Price Kline. GET /v5/market/mark-price-kline. Auth: public. Required: symbol, interval. */
bybit_err bybit_market_mark_price_kline(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get New Delivery Price. GET /v5/market/new-delivery-price. Auth: public. Required: category, baseCoin. */
bybit_err bybit_market_new_delivery_price(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Open Interest. GET /v5/market/open-interest. Auth: public. Required: category, symbol, intervalTime. */
bybit_err bybit_market_open_interest(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* TradFi Integration. GET /v5/market/option-base-coins. Auth: public. Required: agree. */
bybit_err bybit_market_option_base_coins(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Orderbook. GET /v5/market/orderbook. Auth: public. Required: category, symbol. */
bybit_err bybit_market_orderbook(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Premium Index Price Kline. GET /v5/market/premium-index-price-kline. Auth: public. Required: symbol, interval. */
bybit_err bybit_market_premium_index_price_kline(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Order Price Limit. GET /v5/market/price-limit. Auth: public. Required: symbol. */
bybit_err bybit_market_price_limit(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Recent Public Trades. GET /v5/market/recent-trade. Auth: public. Required: category. */
bybit_err bybit_market_recent_trade(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Risk Limit. GET /v5/market/risk-limit. Auth: public. Required: category. */
bybit_err bybit_market_risk_limit(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get RPI Orderbook. GET /v5/market/rpi_orderbook. Auth: public. Required: symbol, limit. */
bybit_err bybit_market_rpi_orderbook(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Tickers. GET /v5/market/tickers. Auth: public. Required: category. */
bybit_err bybit_market_tickers(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Bybit Server Time. GET /v5/market/time. Auth: public. Required: none. */
bybit_err bybit_market_time(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Amend Order. POST /v5/order/amend. Auth: private. Required: category, symbol. */
bybit_err bybit_order_amend(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Batch Amend Order. POST /v5/order/amend-batch. Auth: private. Required: category, request. */
bybit_err bybit_order_amend_batch(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Cancel Order. POST /v5/order/cancel. Auth: private. Required: category, symbol. */
bybit_err bybit_order_cancel(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Cancel All Orders. POST /v5/order/cancel-all. Auth: private. Required: category. */
bybit_err bybit_order_cancel_all(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Batch Cancel Order. POST /v5/order/cancel-batch. Auth: private. Required: category, request. */
bybit_err bybit_order_cancel_batch(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* How To Start Copy Trading. POST /v5/order/create. Auth: private. Required: none. */
bybit_err bybit_order_create(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Batch Place Order. POST /v5/order/create-batch. Auth: private. Required: category, request. */
bybit_err bybit_order_create_batch(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Set Disconnect Cancel All. POST /v5/order/disconnected-cancel-all. Auth: private. Required: timeWindow. */
bybit_err bybit_order_disconnected_cancel_all(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Order History. GET /v5/order/history. Auth: private. Required: category. */
bybit_err bybit_order_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Pre Check Order. POST /v5/order/pre-check. Auth: private. Required: none. */
bybit_err bybit_order_pre_check(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Integration Guidance. GET /v5/order/realtime. Auth: private. Required: none. */
bybit_err bybit_order_realtime(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Borrow Quota (Spot). GET /v5/order/spot-borrow-check. Auth: private. Required: category, symbol, side. */
bybit_err bybit_order_spot_borrow_check(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Add Or Reduce Margin. POST /v5/position/add-margin. Auth: private. Required: category, symbol, margin. */
bybit_err bybit_position_add_margin(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Closed PnL. GET /v5/position/closed-pnl. Auth: private. Required: category. */
bybit_err bybit_position_closed_pnl(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Confirm New Risk Limit. POST /v5/position/confirm-pending-mmr. Auth: private. Required: category, symbol. */
bybit_err bybit_position_confirm_pending_mmr(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Closed Options Positions. GET /v5/position/get-closed-positions. Auth: private. Required: category. */
bybit_err bybit_position_get_closed_positions(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Position Info. GET /v5/position/list. Auth: private. Required: category. */
bybit_err bybit_position_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Move Position History. GET /v5/position/move-history. Auth: private. Required: none. */
bybit_err bybit_position_move_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Move Position. POST /v5/position/move-positions. Auth: private. Required: fromUid, toUid, list. */
bybit_err bybit_position_move_positions(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Set Auto Add Margin. POST /v5/position/set-auto-add-margin. Auth: private. Required: category, symbol, autoAddMargin. */
bybit_err bybit_position_set_auto_add_margin(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Set Leverage. POST /v5/position/set-leverage. Auth: private. Required: category, symbol, buyLeverage, sellLeverage. */
bybit_err bybit_position_set_leverage(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Switch Position Mode. POST /v5/position/switch-mode. Auth: private. Required: category, mode. */
bybit_err bybit_position_switch_mode(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Futures Leverage. GET /v5/position/symbol-info. Auth: private. Required: category. */
bybit_err bybit_position_symbol_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Set Trading Stop. POST /v5/position/trading-stop. Auth: private. Required: category, symbol, tpslMode, positionIdx. */
bybit_err bybit_position_trading_stop(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Pre-upgrade Transaction Log. GET /v5/pre-upgrade/account/transaction-log. Auth: private. Required: category. */
bybit_err bybit_pre_upgrade_account_transaction_log(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Pre-upgrade Delivery Record. GET /v5/pre-upgrade/asset/delivery-record. Auth: private. Required: category. */
bybit_err bybit_pre_upgrade_asset_delivery_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Pre-upgrade USDC Session Settlement. GET /v5/pre-upgrade/asset/settlement-record. Auth: private. Required: category. */
bybit_err bybit_pre_upgrade_asset_settlement_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Pre-upgrade Trade History. GET /v5/pre-upgrade/execution/list. Auth: private. Required: category. */
bybit_err bybit_pre_upgrade_execution_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Pre-upgrade Order History. GET /v5/pre-upgrade/order/history. Auth: private. Required: category. */
bybit_err bybit_pre_upgrade_order_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Pre-upgrade Closed PnL. GET /v5/pre-upgrade/position/closed-pnl. Auth: private. Required: category, symbol. */
bybit_err bybit_pre_upgrade_position_closed_pnl(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Referral Campaign Rewards. POST /v5/referral/campaign/rewards. Auth: private. Required: none. */
bybit_err bybit_referral_campaign_rewards(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Referral Commission Records. POST /v5/referral/commission/records. Auth: private. Required: none. */
bybit_err bybit_referral_commission_records(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Referral User Identity Profile. POST /v5/referral/user/identity-profile. Auth: private. Required: none. */
bybit_err bybit_referral_user_identity_profile(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Referral User Invitations. POST /v5/referral/user/invitations. Auth: private. Required: none. */
bybit_err bybit_referral_user_invitations(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Accept non-LP Quote. POST /v5/rfq/accept-other-quote. Auth: private. Required: rfqId. */
bybit_err bybit_rfq_accept_other_quote(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Cancel All Quotes. POST /v5/rfq/cancel-all-quotes. Auth: private. Required: none. */
bybit_err bybit_rfq_cancel_all_quotes(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Cancel All RFQs. POST /v5/rfq/cancel-all-rfq. Auth: private. Required: none. */
bybit_err bybit_rfq_cancel_all_rfq(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Cancel Quote. POST /v5/rfq/cancel-quote. Auth: private. Required: none. */
bybit_err bybit_rfq_cancel_quote(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Cancel RFQ. POST /v5/rfq/cancel-rfq. Auth: private. Required: none. */
bybit_err bybit_rfq_cancel_rfq(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get RFQ Configuration. GET /v5/rfq/config. Auth: private. Required: none. */
bybit_err bybit_rfq_config(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Create Quote. POST /v5/rfq/create-quote. Auth: private. Required: rfqId. */
bybit_err bybit_rfq_create_quote(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Create RFQ. POST /v5/rfq/create-rfq. Auth: private. Required: counterparties, list. */
bybit_err bybit_rfq_create_rfq(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Execute Quote. POST /v5/rfq/execute-quote. Auth: private. Required: rfqId, quoteId, quoteSide. */
bybit_err bybit_rfq_execute_quote(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Public Trades. GET /v5/rfq/public-trades. Auth: private. Required: none. */
bybit_err bybit_rfq_public_trades(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Quotes. GET /v5/rfq/quote-list. Auth: private. Required: none. */
bybit_err bybit_rfq_quote_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Quotes (real-time). GET /v5/rfq/quote-realtime. Auth: private. Required: none. */
bybit_err bybit_rfq_quote_realtime(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get RFQ Details. GET /v5/rfq/rfq-detail-list. Auth: private. Required: none. */
bybit_err bybit_rfq_rfq_detail_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get RFQs. GET /v5/rfq/rfq-list. Auth: private. Required: none. */
bybit_err bybit_rfq_rfq_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get RFQs (real-time). GET /v5/rfq/rfq-realtime. Auth: private. Required: none. */
bybit_err bybit_rfq_rfq_realtime(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Trade History. GET /v5/rfq/trade-list. Auth: private. Required: none. */
bybit_err bybit_rfq_trade_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Convert Detail. GET /v5/rwa/stocks/convert/detail. Auth: private. Required: none. */
bybit_err bybit_rwa_stocks_convert_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Convert List. GET /v5/rwa/stocks/convert/list. Auth: private. Required: none. */
bybit_err bybit_rwa_stocks_convert_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Submit Convert. POST /v5/rwa/stocks/convert/submit. Auth: private. Required: convertType, symbol, inputAmount, frontMultiplier, requestId, flow. */
bybit_err bybit_rwa_stocks_convert_submit(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Multiplier List. GET /v5/rwa/stocks/market/getMultiplierList. Auth: private. Required: current, pageSize. */
bybit_err bybit_rwa_stocks_market_getMultiplierList(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Market Session. GET /v5/rwa/stocks/market/session. Auth: private. Required: none. */
bybit_err bybit_rwa_stocks_market_session(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Place Stock Order. POST /v5/rwa/stocks/order. Auth: private. Required: symbol, quoteToken, side, type, timeInForce, orderTime, requestId. */
bybit_err bybit_rwa_stocks_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Cancel Stock Order. POST /v5/rwa/stocks/order/cancel. Auth: private. Required: orderNo. */
bybit_err bybit_rwa_stocks_order_cancel(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Stock Order Detail. GET /v5/rwa/stocks/order/detail. Auth: private. Required: none. */
bybit_err bybit_rwa_stocks_order_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Stock Positions. GET /v5/rwa/stocks/positions. Auth: private. Required: none. */
bybit_err bybit_rwa_stocks_positions(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Leverage Token Info. GET /v5/spot-lever-token/info. Auth: public. Required: none. */
bybit_err bybit_spot_lever_token_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Purchase/Redemption Records. GET /v5/spot-lever-token/order-record. Auth: private. Required: none. */
bybit_err bybit_spot_lever_token_order_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Purchase. POST /v5/spot-lever-token/purchase. Auth: private. Required: ltCoin, ltAmount. */
bybit_err bybit_spot_lever_token_purchase(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Redeem. POST /v5/spot-lever-token/redeem. Auth: private. Required: ltCoin. */
bybit_err bybit_spot_lever_token_redeem(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Leveraged Token Market. GET /v5/spot-lever-token/reference. Auth: public. Required: ltCoin. */
bybit_err bybit_spot_lever_token_reference(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Coin State. GET /v5/spot-margin-trade/coinstate. Auth: private. Required: none. */
bybit_err bybit_spot_margin_trade_coinstate(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Tiered Collateral Ratio. GET /v5/spot-margin-trade/collateral. Auth: public. Required: none. */
bybit_err bybit_spot_margin_trade_collateral(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Currency Data. GET /v5/spot-margin-trade/currency-data. Auth: private. Required: none. */
bybit_err bybit_spot_margin_trade_currency_data(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get VIP Margin Data. GET /v5/spot-margin-trade/data. Auth: private. Required: none. */
bybit_err bybit_spot_margin_trade_data(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Fixed-Rate Available Inventory. GET /v5/spot-margin-trade/fixed-available-inventory. Auth: private. Required: currency, term, annualRate. */
bybit_err bybit_spot_margin_trade_fixed_available_inventory(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Fixed-Rate Borrow. POST /v5/spot-margin-trade/fixedborrow. Auth: private. Required: orderCurrency, orderAmount, annualRate, term. */
bybit_err bybit_spot_margin_trade_fixedborrow(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Fixed-Rate Borrow Contract Info. GET /v5/spot-margin-trade/fixedborrow-contract-info. Auth: private. Required: none. */
bybit_err bybit_spot_margin_trade_fixedborrow_contract_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Query Fixed-Rate Borrow Penalty Interest. GET /v5/spot-margin-trade/fixedborrow-interest-accrued. Auth: private. Required: none. */
bybit_err bybit_spot_margin_trade_fixedborrow_interest_accrued(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Cancel Fixed-Rate Borrow Order. POST /v5/spot-margin-trade/fixedborrow-order-cancel. Auth: private. Required: orderId. */
bybit_err bybit_spot_margin_trade_fixedborrow_order_cancel(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Fixed-Rate Borrow Order Info. GET /v5/spot-margin-trade/fixedborrow-order-info. Auth: private. Required: none. */
bybit_err bybit_spot_margin_trade_fixedborrow_order_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Fixed-Rate Borrow Order Quote. GET /v5/spot-margin-trade/fixedborrow-order-quote. Auth: private. Required: orderCurrency. */
bybit_err bybit_spot_margin_trade_fixedborrow_order_quote(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Renew Fixed-Rate Borrow. POST /v5/spot-margin-trade/fixedborrow-renew. Auth: private. Required: loanId. */
bybit_err bybit_spot_margin_trade_fixedborrow_renew(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Flexible Available Inventory. GET /v5/spot-margin-trade/flexible-available-inventory. Auth: private. Required: currency. */
bybit_err bybit_spot_margin_trade_flexible_available_inventory(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Auto Repay Mode. GET /v5/spot-margin-trade/get-auto-repay-mode. Auth: private. Required: none. */
bybit_err bybit_spot_margin_trade_get_auto_repay_mode(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Historical Interest Rate. GET /v5/spot-margin-trade/interest-rate-history. Auth: private. Required: currency. */
bybit_err bybit_spot_margin_trade_interest_rate_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Liability Info. GET /v5/spot-margin-trade/liability. Auth: private. Required: currency. */
bybit_err bybit_spot_margin_trade_liability(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Max Borrowable Amount. GET /v5/spot-margin-trade/max-borrowable. Auth: private. Required: currency. */
bybit_err bybit_spot_margin_trade_max_borrowable(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Position Tiers. GET /v5/spot-margin-trade/position-tiers. Auth: private. Required: none. */
bybit_err bybit_spot_margin_trade_position_tiers(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Available Amount to Repay. GET /v5/spot-margin-trade/repayment-available-amount. Auth: private. Required: currency. */
bybit_err bybit_spot_margin_trade_repayment_available_amount(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Set Auto Repay Mode. POST /v5/spot-margin-trade/set-auto-repay-mode. Auth: private. Required: autoRepayMode. */
bybit_err bybit_spot_margin_trade_set_auto_repay_mode(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Set Leverage. POST /v5/spot-margin-trade/set-leverage. Auth: private. Required: leverage. */
bybit_err bybit_spot_margin_trade_set_leverage(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Status And Leverage. GET /v5/spot-margin-trade/state. Auth: private. Required: none. */
bybit_err bybit_spot_margin_trade_state(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Toggle Margin Trade. POST /v5/spot-margin-trade/switch-mode. Auth: private. Required: spotMarginMode. */
bybit_err bybit_spot_margin_trade_switch_mode(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Launchpool Project List. GET /v5/spot-x/launchpool/project/list. Auth: public. Required: status. */
bybit_err bybit_spot_x_launchpool_project_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Launchpool User Activity Log. POST /v5/spot-x/launchpool/user/activity-log. Auth: private. Required: none. */
bybit_err bybit_spot_x_launchpool_user_activity_log(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Launchpool Current Staking. GET /v5/spot-x/launchpool/user/current-staking. Auth: private. Required: none. */
bybit_err bybit_spot_x_launchpool_user_current_staking(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Launchpool User History. POST /v5/spot-x/launchpool/user/history. Auth: private. Required: none. */
bybit_err bybit_spot_x_launchpool_user_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Puzzle Project List. GET /v5/spot-x/puzzle/project/list. Auth: public. Required: status. */
bybit_err bybit_spot_x_puzzle_project_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Token Splash Project List. GET /v5/spot-x/token-splash/project/list. Auth: public. Required: status. */
bybit_err bybit_spot_x_token_splash_project_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Token Splash User Activity Params. GET /v5/spot-x/token-splash/user/activity-params. Auth: private. Required: none. */
bybit_err bybit_spot_x_token_splash_user_activity_params(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Trade History. GET /v5/spread/execution/list. Auth: private. Required: none. */
bybit_err bybit_spread_execution_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Instruments Info. GET /v5/spread/instrument. Auth: public. Required: none. */
bybit_err bybit_spread_instrument(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Max Qty. GET /v5/spread/max-qty. Auth: private. Required: symbol, side, orderPrice. */
bybit_err bybit_spread_max_qty(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Amend Order. POST /v5/spread/order/amend. Auth: private. Required: symbol. */
bybit_err bybit_spread_order_amend(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Cancel Order. POST /v5/spread/order/cancel. Auth: private. Required: none. */
bybit_err bybit_spread_order_cancel(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Cancel All Orders. POST /v5/spread/order/cancel-all. Auth: private. Required: none. */
bybit_err bybit_spread_order_cancel_all(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Create Order. POST /v5/spread/order/create. Auth: private. Required: symbol, side, orderType, qty. */
bybit_err bybit_spread_order_create(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Order History. GET /v5/spread/order/history. Auth: private. Required: none. */
bybit_err bybit_spread_order_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Open Orders. GET /v5/spread/order/realtime. Auth: private. Required: none. */
bybit_err bybit_spread_order_realtime(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Orderbook. GET /v5/spread/orderbook. Auth: public. Required: symbol. */
bybit_err bybit_spread_orderbook(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Recent Public Trades. GET /v5/spread/recent-trade. Auth: public. Required: symbol. */
bybit_err bybit_spread_recent_trade(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Tickers. GET /v5/spread/tickers. Auth: public. Required: symbol. */
bybit_err bybit_spread_tickers(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Create Strategy Order. POST /v5/strategy/create. Auth: private. Required: none. */
bybit_err bybit_strategy_create(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Strategy List. GET /v5/strategy/list. Auth: private. Required: none. */
bybit_err bybit_strategy_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Strategy Order List. GET /v5/strategy/order-list. Auth: private. Required: strategyId. */
bybit_err bybit_strategy_order_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Stop Strategy. POST /v5/strategy/stop. Auth: private. Required: strategyId. */
bybit_err bybit_strategy_stop(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get System Status. GET /v5/system/status. Auth: public. Required: none. */
bybit_err bybit_system_status(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Affiliate User Info. GET /v5/user/aff-customer-info. Auth: private. Required: uid. */
bybit_err bybit_user_aff_customer_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* TradFi Integration. POST /v5/user/agreement. Auth: private. Required: agree. */
bybit_err bybit_user_agreement(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Demo Trading Service. POST /v5/user/create-demo-member. Auth: private. Required: none. */
bybit_err bybit_user_create_demo_member(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Create Sub UID API Key. POST /v5/user/create-sub-api. Auth: private. Required: subuid, readOnly, permissions. */
bybit_err bybit_user_create_sub_api(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Create Sub UID. POST /v5/user/create-sub-member. Auth: private. Required: username, memberType. */
bybit_err bybit_user_create_sub_member(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Delete Sub UID. POST /v5/user/del-submember. Auth: private. Required: subMemberId. */
bybit_err bybit_user_del_submember(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Delete Master API Key. POST /v5/user/delete-api. Auth: private. Required: none. */
bybit_err bybit_user_delete_api(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Delete Sub API Key. POST /v5/user/delete-sub-api. Auth: private. Required: none. */
bybit_err bybit_user_delete_sub_api(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Fund Custodial Sub Acct. GET /v5/user/escrow_sub_members. Auth: private. Required: none. */
bybit_err bybit_user_escrow_sub_members(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Freeze Sub UID. POST /v5/user/frozen-sub-member. Auth: private. Required: subuid, frozen. */
bybit_err bybit_user_frozen_sub_member(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get UID Wallet Type. GET /v5/user/get-member-type. Auth: private. Required: none. */
bybit_err bybit_user_get_member_type(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Referral Code. GET /v5/user/invitation/code. Auth: private. Required: none. */
bybit_err bybit_user_invitation_code(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Friend Referrals. GET /v5/user/invitation/referrals. Auth: private. Required: none. */
bybit_err bybit_user_invitation_referrals(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get API Key Information. GET /v5/user/query-api. Auth: private. Required: none. */
bybit_err bybit_user_query_api(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Sub UID List (Limited). GET /v5/user/query-sub-members. Auth: private. Required: none. */
bybit_err bybit_user_query_sub_members(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Sub Account All API Keys. GET /v5/user/sub-apikeys. Auth: private. Required: subMemberId. */
bybit_err bybit_user_sub_apikeys(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Get Sub UID List (Unlimited). GET /v5/user/submembers. Auth: private. Required: none. */
bybit_err bybit_user_submembers(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Modify Master API Key. POST /v5/user/update-api. Auth: private. Required: none. */
bybit_err bybit_user_update_api(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

/* Modify Sub API Key. POST /v5/user/update-sub-api. Auth: private. Required: none. */
bybit_err bybit_user_update_sub_api(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out);

#ifdef __cplusplus
}
#endif

#endif /* BYBIT_ENDPOINTS_H */
