/* Generated from bybit-exchange/docs d5a43d2d010c4468e3f7d992408eaff88a48068a. Do not edit. */
#include "bybit/endpoints.h"

const bybit_endpoint bybit_endpoint_table[] = {
    { "bybit_account_borrow", "POST", "/v5/account/borrow", "Manual Borrow", "account/borrow.mdx", "coin, amount", 1 },
    { "bybit_account_borrow_history", "GET", "/v5/account/borrow-history", "Get Borrow History", "account/borrow-history.mdx", "", 1 },
    { "bybit_account_collateral_info", "GET", "/v5/account/collateral-info", "Get Collateral Info", "account/collateral-info.mdx", "", 1 },
    { "bybit_account_demo_apply_money", "POST", "/v5/account/demo-apply-money", "Demo Trading Service", "demo.mdx", "", 1 },
    { "bybit_account_fee_rate", "GET", "/v5/account/fee-rate", "Get Fee Rate", "account/fee-rate.mdx", "", 1 },
    { "bybit_account_info", "GET", "/v5/account/info", "Get Account Info", "account/account-info.mdx", "", 1 },
    { "bybit_account_instruments_info", "GET", "/v5/account/instruments-info", "Get Account Instruments Info", "account/instrument.mdx", "category", 1 },
    { "bybit_account_mmp_modify", "POST", "/v5/account/mmp-modify", "Set MMP", "account/set-mmp.mdx", "baseCoin, window, frozenPeriod, qtyLimit, deltaLimit", 1 },
    { "bybit_account_mmp_reset", "POST", "/v5/account/mmp-reset", "Reset MMP", "account/reset-mmp.mdx", "baseCoin", 1 },
    { "bybit_account_mmp_state", "GET", "/v5/account/mmp-state", "Get MMP State", "account/get-mmp-state.mdx", "baseCoin", 1 },
    { "bybit_account_no_convert_repay", "POST", "/v5/account/no-convert-repay", "Manual Repay Without Asset Conversion", "account/no-convert-repay.mdx", "coin", 1 },
    { "bybit_account_option_asset_info", "GET", "/v5/account/option-asset-info", "Get Option Asset Info", "account/option-asset-info.mdx", "", 1 },
    { "bybit_account_pay_info", "GET", "/v5/account/pay-info", "Get Pay Info", "account/pay-info.mdx", "", 1 },
    { "bybit_account_query_dcp_info", "GET", "/v5/account/query-dcp-info", "Get DCP Info", "account/dcp-info.mdx", "", 1 },
    { "bybit_account_quick_repayment", "POST", "/v5/account/quick-repayment", "Repay Liability", "account/repay-liability.mdx", "", 1 },
    { "bybit_account_repay", "POST", "/v5/account/repay", "Manual Repay", "account/repay.mdx", "", 1 },
    { "bybit_account_set_collateral_switch", "POST", "/v5/account/set-collateral-switch", "Set Collateral Coin", "account/set-collateral.mdx", "coin, collateralSwitch", 1 },
    { "bybit_account_set_collateral_switch_batch", "POST", "/v5/account/set-collateral-switch-batch", "Batch Set Collateral Coin", "account/batch-set-collateral.mdx", "request", 1 },
    { "bybit_account_set_delta_mode", "POST", "/v5/account/set-delta-mode", "Set Delta Neutral Mode", "account/set-delta-mode.mdx", "deltaEnable", 1 },
    { "bybit_account_set_hedging_mode", "POST", "/v5/account/set-hedging-mode", "Set Spot Hedging", "account/set-spot-hedge.mdx", "setHedgingMode", 1 },
    { "bybit_account_set_limit_px_action", "POST", "/v5/account/set-limit-px-action", "Set Price Limit Behaviour", "account/set-price-limit.mdx", "category, modifyEnable", 1 },
    { "bybit_account_set_margin_mode", "POST", "/v5/account/set-margin-mode", "Set Margin Mode", "account/set-margin-mode.mdx", "setMarginMode", 1 },
    { "bybit_account_smp_group", "GET", "/v5/account/smp-group", "Get SMP Group ID", "account/smp-group.mdx", "", 1 },
    { "bybit_account_trade_info_for_analysis", "GET", "/v5/account/trade-info-for-analysis", "Get Trade Info For Analysis", "account/trade-info-for-analysis.mdx", "symbol", 1 },
    { "bybit_account_transaction_log", "GET", "/v5/account/transaction-log", "Get Transaction Log", "account/transaction-log.mdx", "", 1 },
    { "bybit_account_upgrade_to_uta", "POST", "/v5/account/upgrade-to-uta", "Upgrade to Unified Account Pro", "account/upgrade-unified-account.mdx", "", 1 },
    { "bybit_account_user_setting_config", "GET", "/v5/account/user-setting-config", "Get Trade Behaviour Config", "account/get-user-setting-config.mdx", "", 1 },
    { "bybit_account_wallet_balance", "GET", "/v5/account/wallet-balance", "Get Wallet Balance", "account/wallet-balance.mdx", "accountType", 1 },
    { "bybit_account_withdrawal", "GET", "/v5/account/withdrawal", "Get Transferable Amount (Unified)", "account/unified-trans-amnt.mdx", "coinName", 1 },
    { "bybit_affiliate_aff_user_list", "GET", "/v5/affiliate/aff-user-list", "Get Affiliate User List", "affiliate/affiliate-user-list.mdx", "", 1 },
    { "bybit_affiliate_affiliate_sub_list", "GET", "/v5/affiliate/affiliate-sub-list", "Get Affiliate Sub-Affiliate List", "affiliate/affiliate-sub-list.mdx", "", 1 },
    { "bybit_alpha_lp_order_list", "POST", "/v5/alpha/lp/order-list", "Get LP Order List", "alpha/lp/order-list.mdx", "", 1 },
    { "bybit_alpha_lp_pay_token_list", "POST", "/v5/alpha/lp/pay-token-list", "Get LP Pay Token List", "alpha/lp/pay-token-list.mdx", "", 1 },
    { "bybit_alpha_lp_pay_token_price", "POST", "/v5/alpha/lp/pay-token-price", "Get LP Pay Token Price", "alpha/lp/pay-token-price.mdx", "tokenCode", 1 },
    { "bybit_alpha_lp_pool_info", "POST", "/v5/alpha/lp/pool-info", "Get LP Pool Info", "alpha/lp/pool-info.mdx", "poolAddress", 1 },
    { "bybit_alpha_lp_pool_list", "POST", "/v5/alpha/lp/pool-list", "Get LP Pool List", "alpha/lp/pool-list.mdx", "", 1 },
    { "bybit_alpha_lp_position_list", "POST", "/v5/alpha/lp/position-list", "Get LP Position List", "alpha/lp/position-list.mdx", "", 1 },
    { "bybit_alpha_lp_redeem", "POST", "/v5/alpha/lp/redeem", "Execute LP Redeem", "alpha/lp/redeem.mdx", "positionId, poolAddress, dercRatio", 1 },
    { "bybit_alpha_lp_stake", "POST", "/v5/alpha/lp/stake", "Execute LP Stake", "alpha/lp/stake.mdx", "positionId, poolAddress, payTokenAmount, payTokenCode", 1 },
    { "bybit_alpha_prediction_buy", "POST", "/v5/alpha/prediction/buy", "Execute Buy", "alpha/prediction/buy.mdx", "tokenId, amount, payTokenCode, orderType, slippage, eventId", 1 },
    { "bybit_alpha_prediction_engine_status", "GET", "/v5/alpha/prediction/engine-status", "Get Engine Status", "alpha/prediction/engine-status.mdx", "", 1 },
    { "bybit_alpha_prediction_event_detail", "POST", "/v5/alpha/prediction/event-detail", "Get Event Detail", "alpha/prediction/event-detail.mdx", "", 1 },
    { "bybit_alpha_prediction_order_book", "POST", "/v5/alpha/prediction/order-book", "Get Order Book", "alpha/prediction/order-book.mdx", "tokenIds", 1 },
    { "bybit_alpha_prediction_order_estimate", "POST", "/v5/alpha/prediction/order-estimate", "Get Order Estimate", "alpha/prediction/order-estimate.mdx", "tokenId, side, eventId, amount, orderType", 1 },
    { "bybit_alpha_prediction_order_list", "POST", "/v5/alpha/prediction/order-list", "Get Order List", "alpha/prediction/order-list.mdx", "", 1 },
    { "bybit_alpha_prediction_pay_token_list", "GET", "/v5/alpha/prediction/pay-token-list", "Get Payment Token List", "alpha/prediction/pay-token-list.mdx", "", 1 },
    { "bybit_alpha_prediction_portfolio_summary", "POST", "/v5/alpha/prediction/portfolio-summary", "Get Portfolio Summary", "alpha/prediction/portfolio-summary.mdx", "", 1 },
    { "bybit_alpha_prediction_position_history", "POST", "/v5/alpha/prediction/position-history", "Get Position History", "alpha/prediction/position-history.mdx", "", 1 },
    { "bybit_alpha_prediction_position_list", "POST", "/v5/alpha/prediction/position-list", "Get Position List", "alpha/prediction/position-list.mdx", "", 1 },
    { "bybit_alpha_prediction_price_history", "POST", "/v5/alpha/prediction/price-history", "Get Price History", "alpha/prediction/price-history.mdx", "tokenId, interval", 1 },
    { "bybit_alpha_prediction_sell", "POST", "/v5/alpha/prediction/sell", "Execute Sell", "alpha/prediction/sell.mdx", "tokenId, size, orderType, slippage, eventId", 1 },
    { "bybit_alpha_prediction_side_market_list", "POST", "/v5/alpha/prediction/side-market-list", "Get Side Market List", "alpha/prediction/side-market-list.mdx", "eventId", 1 },
    { "bybit_alpha_prediction_sports_group_stage_detail", "POST", "/v5/alpha/prediction/sports/group-stage-detail", "Get Sports Group Stage Detail", "alpha/prediction/sports-group-stage-detail.mdx", "eventType", 1 },
    { "bybit_alpha_prediction_sports_match_list", "POST", "/v5/alpha/prediction/sports/match-list", "Get Sports Match List", "alpha/prediction/sports-match-list.mdx", "eventType", 1 },
    { "bybit_alpha_prediction_sports_timeline_stages", "GET", "/v5/alpha/prediction/sports/timeline-stages", "Get Sports Timeline Stages", "alpha/prediction/sports-timeline-stages.mdx", "eventType", 1 },
    { "bybit_alpha_prediction_token_price", "POST", "/v5/alpha/prediction/token-price", "Get Token Price", "alpha/prediction/token-price.mdx", "tokenIds", 1 },
    { "bybit_alpha_trade_asset_detail", "POST", "/v5/alpha/trade/asset-detail", "Get Asset Detail", "alpha/trade/asset-detail.mdx", "chainCode, tokenAddress", 1 },
    { "bybit_alpha_trade_asset_list", "POST", "/v5/alpha/trade/asset-list", "Get Asset List", "alpha/trade/asset-list.mdx", "", 1 },
    { "bybit_alpha_trade_biz_token_details", "POST", "/v5/alpha/trade/biz-token-details", "Get Token Details", "alpha/trade/biz-token-details.mdx", "chainCode, tokenAddress", 1 },
    { "bybit_alpha_trade_biz_token_list", "POST", "/v5/alpha/trade/biz-token-list", "Get Biz Token List", "alpha/trade/biz-token-list.mdx", "", 1 },
    { "bybit_alpha_trade_biz_token_price_list", "POST", "/v5/alpha/trade/biz-token-price-list", "Get Token Price List", "alpha/trade/biz-token-price-list.mdx", "tokenAddressInfo", 1 },
    { "bybit_alpha_trade_order_list", "POST", "/v5/alpha/trade/order-list", "Get Order List", "alpha/trade/order-list.mdx", "limit, pageIndex", 1 },
    { "bybit_alpha_trade_pay_token_list", "POST", "/v5/alpha/trade/pay-token-list", "Get Payment Token List", "alpha/trade/pay-token-list.mdx", "chainCode, tokenAddress", 1 },
    { "bybit_alpha_trade_purchase", "POST", "/v5/alpha/trade/purchase", "Execute Purchase", "alpha/trade/trade-purchase.mdx", "fromTokenCode, fromTokenAmount, toTokenCode, slippage, quoteData, gas, quoteMode, correctingCode", 1 },
    { "bybit_alpha_trade_quote", "POST", "/v5/alpha/trade/quote", "Get Trade Quote", "alpha/trade/trade-quote.mdx", "tradeType, fromTokenCode, fromTokenAmount, toTokenCode", 1 },
    { "bybit_alpha_trade_redeem", "POST", "/v5/alpha/trade/redeem", "Execute Redeem", "alpha/trade/trade-redeem.mdx", "fromTokenCode, fromTokenAmount, toTokenCode, slippage, quoteData, gas, quoteMode, correctingCode", 1 },
    { "bybit_announcements_index", "GET", "/v5/announcements/index", "Get Announcement", "announcement.mdx", "locale", 0 },
    { "bybit_apilimit_query", "GET", "/v5/apilimit/query", "Get Rate Limit", "rate-limit/rules-for-pros/apilimit-query.mdx", "uids", 1 },
    { "bybit_apilimit_query_all", "GET", "/v5/apilimit/query-all", "Get All Rate Limits", "rate-limit/rules-for-pros/apilimit-query-all.mdx", "", 1 },
    { "bybit_apilimit_query_cap", "GET", "/v5/apilimit/query-cap", "Get Rate Limit Cap", "rate-limit/rules-for-pros/apilimit-query-cap.mdx", "", 1 },
    { "bybit_apilimit_set", "POST", "/v5/apilimit/set", "Set Rate Limit", "rate-limit/rules-for-pros/apilimit-set.mdx", "list", 1 },
    { "bybit_asset_asset_overview", "GET", "/v5/asset/asset-overview", "Asset Overview", "asset/balance/asset-overview.mdx", "", 1 },
    { "bybit_asset_coin_greeks", "GET", "/v5/asset/coin-greeks", "Get Coin Greeks", "account/coin-greeks.mdx", "", 1 },
    { "bybit_asset_coin_query_info", "GET", "/v5/asset/coin/query-info", "Get Coin Info", "asset/coin-info.mdx", "", 1 },
    { "bybit_asset_covert_get_quote", "POST", "/v5/asset/covert/get-quote", "Request a Quote", "asset/convert-small-balance/request-quote.mdx", "accountType, fromCoinList, toCoin", 1 },
    { "bybit_asset_covert_small_balance_execute", "POST", "/v5/asset/covert/small-balance-execute", "Confirm a Quote", "asset/convert-small-balance/confirm-quote.mdx", "quoteId", 1 },
    { "bybit_asset_covert_small_balance_history", "GET", "/v5/asset/covert/small-balance-history", "Get Exchange History", "asset/convert-small-balance/exchange-history.mdx", "", 1 },
    { "bybit_asset_covert_small_balance_list", "GET", "/v5/asset/covert/small-balance-list", "Get Small Balance Coins", "asset/convert-small-balance/small-balanc-coins.mdx", "accountType", 1 },
    { "bybit_asset_delivery_record", "GET", "/v5/asset/delivery-record", "Get Delivery Record", "asset/delivery.mdx", "category", 1 },
    { "bybit_asset_deposit_deposit_to_account", "POST", "/v5/asset/deposit/deposit-to-account", "Set Deposit Account", "asset/deposit/set-deposit-acct.mdx", "accountType", 1 },
    { "bybit_asset_deposit_query_address", "GET", "/v5/asset/deposit/query-address", "Get Master Deposit Address", "asset/deposit/master-deposit-addr.mdx", "coin", 1 },
    { "bybit_asset_deposit_query_internal_record", "GET", "/v5/asset/deposit/query-internal-record", "Get Internal Deposit Records (off-chain)", "asset/deposit/internal-deposit-record.mdx", "", 1 },
    { "bybit_asset_deposit_query_record", "GET", "/v5/asset/deposit/query-record", "Get Deposit Records (on-chain)", "asset/deposit/deposit-record.mdx", "", 1 },
    { "bybit_asset_deposit_query_sub_member_address", "GET", "/v5/asset/deposit/query-sub-member-address", "Get Sub Deposit Address", "asset/deposit/sub-deposit-addr.mdx", "coin, chainType, subMemberId", 1 },
    { "bybit_asset_deposit_query_sub_member_record", "GET", "/v5/asset/deposit/query-sub-member-record", "Get Sub Deposit Records (on-chain)", "asset/deposit/sub-deposit-record.mdx", "subMemberId", 1 },
    { "bybit_asset_exchange_convert_execute", "POST", "/v5/asset/exchange/convert-execute", "Confirm a Quote", "asset/convert/confirm-quote.mdx", "quoteTxId", 1 },
    { "bybit_asset_exchange_convert_result_query", "GET", "/v5/asset/exchange/convert-result-query", "Get Convert Status", "asset/convert/get-convert-result.mdx", "quoteTxId, accountType", 1 },
    { "bybit_asset_exchange_order_record", "GET", "/v5/asset/exchange/order-record", "Get Coin Exchange Records", "asset/exchange.mdx", "", 1 },
    { "bybit_asset_exchange_query_coin_list", "GET", "/v5/asset/exchange/query-coin-list", "Get Convert Coin List", "asset/convert/convert-coin-list.mdx", "accountType", 1 },
    { "bybit_asset_exchange_query_convert_history", "GET", "/v5/asset/exchange/query-convert-history", "Get Convert History", "asset/convert/get-convert-history.mdx", "", 1 },
    { "bybit_asset_exchange_quote_apply", "POST", "/v5/asset/exchange/quote-apply", "Request a Quote", "asset/convert/apply-quote.mdx", "accountType, fromCoin, toCoin, requestCoin, requestAmount", 1 },
    { "bybit_asset_fundinghistory", "GET", "/v5/asset/fundinghistory", "Funding Account Transaction History", "asset/fund-history.mdx", "", 1 },
    { "bybit_asset_portfolio_margin", "GET", "/v5/asset/portfolio-margin", "Get Portfolio Margin Info", "asset/portfolio-margin.mdx", "", 1 },
    { "bybit_asset_settlement_record", "GET", "/v5/asset/settlement-record", "Get USDC Session Settlement", "asset/settlement.mdx", "category", 1 },
    { "bybit_asset_total_members_assets", "GET", "/v5/asset/total-members-assets", "Get Total Members Assets", "asset/total-members-assets.mdx", "", 1 },
    { "bybit_asset_transfer_inter_transfer", "POST", "/v5/asset/transfer/inter-transfer", "Create Internal Transfer", "asset/transfer/create-inter-transfer.mdx", "transferId, coin, amount, fromAccountType, toAccountType", 1 },
    { "bybit_asset_transfer_query_account_coin_balance", "GET", "/v5/asset/transfer/query-account-coin-balance", "Get Single Coin Balance", "asset/balance/account-coin-balance.mdx", "accountType, coin", 1 },
    { "bybit_asset_transfer_query_account_coins_balance", "GET", "/v5/asset/transfer/query-account-coins-balance", "Get All Coins Balance", "asset/balance/all-balance.mdx", "accountType", 1 },
    { "bybit_asset_transfer_query_inter_transfer_list", "GET", "/v5/asset/transfer/query-inter-transfer-list", "Get Internal Transfer Records", "asset/transfer/inter-transfer-list.mdx", "", 1 },
    { "bybit_asset_transfer_query_sub_member_list", "GET", "/v5/asset/transfer/query-sub-member-list", "Get Sub UID", "asset/sub-uid-list.mdx", "", 1 },
    { "bybit_asset_transfer_query_transfer_coin_list", "GET", "/v5/asset/transfer/query-transfer-coin-list", "Get Transferable Coin", "asset/transfer/transferable-coin.mdx", "fromAccountType, toAccountType", 1 },
    { "bybit_asset_transfer_query_universal_transfer_list", "GET", "/v5/asset/transfer/query-universal-transfer-list", "Get Universal Transfer Records", "asset/transfer/unitransfer-list.mdx", "", 1 },
    { "bybit_asset_transfer_universal_transfer", "POST", "/v5/asset/transfer/universal-transfer", "Create Universal Transfer", "asset/transfer/unitransfer.mdx", "transferId, coin, amount, fromMemberId, toMemberId, fromAccountType, toAccountType", 1 },
    { "bybit_asset_travel_rule_deposit_submit", "POST", "/v5/asset/travel-rule/deposit/submit", "Submit Deposit Originator Info", "asset/deposit/submit-info.mdx", "depositId, questionnaire", 1 },
    { "bybit_asset_withdraw_cancel", "POST", "/v5/asset/withdraw/cancel", "Cancel Withdrawal", "asset/withdraw/cancel-withdraw.mdx", "id", 1 },
    { "bybit_asset_withdraw_create", "POST", "/v5/asset/withdraw/create", "Withdraw", "asset/withdraw/withdraw.mdx", "coin, address, amount, timestamp, accountType", 1 },
    { "bybit_asset_withdraw_query_address", "GET", "/v5/asset/withdraw/query-address", "Get Withdrawal Address List", "asset/withdraw/withdraw-address.mdx", "", 1 },
    { "bybit_asset_withdraw_query_record", "GET", "/v5/asset/withdraw/query-record", "Get Withdrawal Records", "asset/withdraw/withdraw-record.mdx", "", 1 },
    { "bybit_asset_withdraw_vasp_list", "GET", "/v5/asset/withdraw/vasp/list", "Get available VASPs", "asset/withdraw/vasp-list.mdx", "", 1 },
    { "bybit_asset_withdraw_withdrawable_amount", "GET", "/v5/asset/withdraw/withdrawable-amount", "Get Withdrawable Amount", "asset/balance/delay-amount.mdx", "coin", 1 },
    { "bybit_broker_account_info", "GET", "/v5/broker/account-info", "Get Account Info", "broker/exchange-broker/account-info.mdx", "", 1 },
    { "bybit_broker_apilimit_query_all", "GET", "/v5/broker/apilimit/query-all", "Get All Rate Limits", "broker/exchange-broker/rate-limit/query-all.mdx", "", 1 },
    { "bybit_broker_apilimit_query_cap", "GET", "/v5/broker/apilimit/query-cap", "Get Rate Limit Cap", "broker/exchange-broker/rate-limit/query-cap.mdx", "", 1 },
    { "bybit_broker_apilimit_set", "POST", "/v5/broker/apilimit/set", "Set Rate Limit", "broker/exchange-broker/rate-limit/set.mdx", "list", 1 },
    { "bybit_broker_asset_query_sub_member_deposit_record", "GET", "/v5/broker/asset/query-sub-member-deposit-record", "Get Sub Account Deposit Records", "broker/exchange-broker/sub-deposit-record.mdx", "", 1 },
    { "bybit_broker_award_distribute_award", "POST", "/v5/broker/award/distribute-award", "Issue Voucher", "broker/reward/issue-voucher.mdx", "accountId, awardId, specCode, amount, brokerId", 1 },
    { "bybit_broker_award_distribution_record", "POST", "/v5/broker/award/distribution-record", "Get Issued Voucher", "broker/reward/get-issue-voucher.mdx", "accountId, awardId, specCode", 1 },
    { "bybit_broker_award_info", "POST", "/v5/broker/award/info", "Get Voucher Spec", "broker/reward/voucher.mdx", "id", 1 },
    { "bybit_broker_earnings_info", "GET", "/v5/broker/earnings-info", "Get Earning", "broker/exchange-broker/exchange-earning.mdx", "", 1 },
    { "bybit_broker_ip_changelog", "GET", "/v5/broker/ip/changelog", "Get Broker IP Change Log", "broker/api-broker/ip-changelog.mdx", "", 1 },
    { "bybit_broker_whitelist_ip", "GET", "/v5/broker/whitelist/ip", "Get Broker Whitelist IP", "broker/api-broker/whitelist-ip.mdx", "", 0 },
    { "bybit_card_reward_mall_item_list", "POST", "/v5/card/reward/mall/item/list", "Query Mall Item List", "bybit-card/point/item-list.mdx", "", 1 },
    { "bybit_card_reward_point_cashback_detail", "POST", "/v5/card/reward/point/cashback/detail", "Query Cashback Detail", "bybit-card/point/cashback-detail.mdx", "bizTxnId", 1 },
    { "bybit_card_reward_points_balance", "POST", "/v5/card/reward/points/balance", "Query Point Balance", "bybit-card/point/balance.mdx", "", 1 },
    { "bybit_card_reward_points_records", "POST", "/v5/card/reward/points/records", "Query Point Records", "bybit-card/point/records.mdx", "", 1 },
    { "bybit_card_reward_points_tier", "POST", "/v5/card/reward/points/tier", "Query Tier Info", "bybit-card/point/tier.mdx", "", 1 },
    { "bybit_card_transaction_query_asset_records", "POST", "/v5/card/transaction/query-asset-records", "Query Asset Records", "bybit-card/asset-records.mdx", "", 1 },
    { "bybit_compliance_appeal_commit", "POST", "/v5/compliance/appeal/commit", "Commit Appeal", "tm-onchain/appeal-commit.mdx", "appealId, itemsData", 1 },
    { "bybit_compliance_appeal_detail", "GET", "/v5/compliance/appeal/detail", "Get Appeal Detail", "tm-onchain/appeal-detail.mdx", "appealId", 1 },
    { "bybit_compliance_appeal_list", "GET", "/v5/compliance/appeal/list", "Get Appeal List", "tm-onchain/appeal-list.mdx", "", 1 },
    { "bybit_crypto_loan_common_adjust_ltv", "POST", "/v5/crypto-loan-common/adjust-ltv", "Adjust Collateral Amount", "new-crypto-loan/adjust-collateral.mdx", "currency, amount, direction", 1 },
    { "bybit_crypto_loan_common_adjustment_history", "GET", "/v5/crypto-loan-common/adjustment-history", "Get Collateral Adjustment History", "new-crypto-loan/ltv-adjust-history.mdx", "", 1 },
    { "bybit_crypto_loan_common_collateral_data", "GET", "/v5/crypto-loan-common/collateral-data", "Get Collateral Coins", "new-crypto-loan/collateral-coin.mdx", "", 0 },
    { "bybit_crypto_loan_common_loanable_data", "GET", "/v5/crypto-loan-common/loanable-data", "Get Borrowable Coins", "new-crypto-loan/loan-coin.mdx", "", 0 },
    { "bybit_crypto_loan_common_max_collateral_amount", "GET", "/v5/crypto-loan-common/max-collateral-amount", "Get Max. Allowed Collateral Reduction Amount", "new-crypto-loan/reduce-max-collateral-amt.mdx", "currency", 1 },
    { "bybit_crypto_loan_common_max_loan", "POST", "/v5/crypto-loan-common/max-loan", "Obtain Max Loan Amount", "new-crypto-loan/max-loan-amt.mdx", "currency", 1 },
    { "bybit_crypto_loan_common_position", "GET", "/v5/crypto-loan-common/position", "Get Crypto Loan Position", "new-crypto-loan/crypto-loan-position.mdx", "", 1 },
    { "bybit_crypto_loan_fixed_available_inventory", "GET", "/v5/crypto-loan-fixed/available-inventory", "Get Available Inventory", "new-crypto-loan/fixed/available-inventory.mdx", "currency, term, annualRate", 1 },
    { "bybit_crypto_loan_fixed_borrow", "POST", "/v5/crypto-loan-fixed/borrow", "Create Borrow Order", "new-crypto-loan/fixed/borrow.mdx", "orderCurrency, orderAmount, annualRate, term", 1 },
    { "bybit_crypto_loan_fixed_borrow_contract_info", "GET", "/v5/crypto-loan-fixed/borrow-contract-info", "Get Borrow Contract Info", "new-crypto-loan/fixed/borrow-contract.mdx", "", 1 },
    { "bybit_crypto_loan_fixed_borrow_order_cancel", "POST", "/v5/crypto-loan-fixed/borrow-order-cancel", "Cancel Borrow Order", "new-crypto-loan/fixed/cancel-borrow.mdx", "orderId", 1 },
    { "bybit_crypto_loan_fixed_borrow_order_info", "GET", "/v5/crypto-loan-fixed/borrow-order-info", "Get Borrow Order Info", "new-crypto-loan/fixed/borrow-order.mdx", "", 1 },
    { "bybit_crypto_loan_fixed_borrow_order_quote", "GET", "/v5/crypto-loan-fixed/borrow-order-quote", "Get Borrowing Market", "new-crypto-loan/fixed/borrow-market.mdx", "orderCurrency, orderBy", 1 },
    { "bybit_crypto_loan_fixed_fully_repay", "POST", "/v5/crypto-loan-fixed/fully-repay", "Repay", "new-crypto-loan/fixed/repay.mdx", "", 1 },
    { "bybit_crypto_loan_fixed_renew", "POST", "/v5/crypto-loan-fixed/renew", "Renew Borrow Order", "new-crypto-loan/fixed/renew.mdx", "loanId", 1 },
    { "bybit_crypto_loan_fixed_renew_info", "GET", "/v5/crypto-loan-fixed/renew-info", "Get Renew Order Info", "new-crypto-loan/fixed/renew-order.mdx", "", 1 },
    { "bybit_crypto_loan_fixed_repay_collateral", "POST", "/v5/crypto-loan-fixed/repay-collateral", "Collateral Repayment", "new-crypto-loan/fixed/repay-collateral.mdx", "loanCurrency, collateralCoin, amount", 1 },
    { "bybit_crypto_loan_fixed_repayment_history", "GET", "/v5/crypto-loan-fixed/repayment-history", "Get Repayment History", "new-crypto-loan/fixed/repay-history.mdx", "", 1 },
    { "bybit_crypto_loan_fixed_supply", "POST", "/v5/crypto-loan-fixed/supply", "Create Supply Order", "new-crypto-loan/fixed/supply.mdx", "orderCurrency, orderAmount, annualRate, term", 1 },
    { "bybit_crypto_loan_fixed_supply_contract_info", "GET", "/v5/crypto-loan-fixed/supply-contract-info", "Get Supply Contract Info", "new-crypto-loan/fixed/supply-contract copy.mdx", "", 1 },
    { "bybit_crypto_loan_fixed_supply_order_cancel", "POST", "/v5/crypto-loan-fixed/supply-order-cancel", "Cancel Supply Order", "new-crypto-loan/fixed/cancel-supply.mdx", "orderId", 1 },
    { "bybit_crypto_loan_fixed_supply_order_info", "GET", "/v5/crypto-loan-fixed/supply-order-info", "Get Supply Order Info", "new-crypto-loan/fixed/supply-order.mdx", "", 1 },
    { "bybit_crypto_loan_fixed_supply_order_quote", "GET", "/v5/crypto-loan-fixed/supply-order-quote", "Get Lending Market", "new-crypto-loan/fixed/supply-market.mdx", "orderCurrency, orderBy", 1 },
    { "bybit_crypto_loan_flexible_available_inventory", "GET", "/v5/crypto-loan-flexible/available-inventory", "Get Available Inventory", "new-crypto-loan/flexible/available-inventory.mdx", "currency", 1 },
    { "bybit_crypto_loan_flexible_borrow", "POST", "/v5/crypto-loan-flexible/borrow", "Borrow", "new-crypto-loan/flexible/borrow.mdx", "loanCurrency, loanAmount", 1 },
    { "bybit_crypto_loan_flexible_borrow_history", "GET", "/v5/crypto-loan-flexible/borrow-history", "Get Borrowing History", "new-crypto-loan/flexible/loan-orders.mdx", "", 1 },
    { "bybit_crypto_loan_flexible_ongoing_coin", "GET", "/v5/crypto-loan-flexible/ongoing-coin", "Get Flexible Loans", "new-crypto-loan/flexible/unpaid-loan-order.mdx", "", 1 },
    { "bybit_crypto_loan_flexible_repay", "POST", "/v5/crypto-loan-flexible/repay", "Repay", "new-crypto-loan/flexible/repay.mdx", "loanCurrency, amount", 1 },
    { "bybit_crypto_loan_flexible_repay_collateral", "POST", "/v5/crypto-loan-flexible/repay-collateral", "Collateral Repayment", "new-crypto-loan/flexible/repay-collateral.mdx", "loanCurrency, collateralCoin, amount", 1 },
    { "bybit_crypto_loan_flexible_repayment_history", "GET", "/v5/crypto-loan-flexible/repayment-history", "Get Repayment History", "new-crypto-loan/flexible/repay-orders.mdx", "", 1 },
    { "bybit_crypto_loan_adjust_ltv", "POST", "/v5/crypto-loan/adjust-ltv", "Adjust Collateral Amount", "crypto-loan/adjust-collateral.mdx", "orderId, amount, direction", 1 },
    { "bybit_crypto_loan_adjustment_history", "GET", "/v5/crypto-loan/adjustment-history", "Get Loan LTV Adjustment History", "crypto-loan/ltv-adjust-history.mdx", "", 1 },
    { "bybit_crypto_loan_borrow_history", "GET", "/v5/crypto-loan/borrow-history", "Get Completed Loan History", "crypto-loan/completed-loan-order.mdx", "", 1 },
    { "bybit_crypto_loan_borrowable_collateralisable_number", "GET", "/v5/crypto-loan/borrowable-collateralisable-number", "Get Account Borrowable/Collateralizable Limit", "crypto-loan/acct-borrow-collateral.mdx", "loanCurrency, collateralCurrency", 1 },
    { "bybit_crypto_loan_collateral_data", "GET", "/v5/crypto-loan/collateral-data", "Get Collateral Coins", "crypto-loan/collateral-coin.mdx", "", 0 },
    { "bybit_crypto_loan_loanable_data", "GET", "/v5/crypto-loan/loanable-data", "Get Borrowable Coins", "crypto-loan/loan-coin.mdx", "", 0 },
    { "bybit_crypto_loan_max_collateral_amount", "GET", "/v5/crypto-loan/max-collateral-amount", "Get Max. Allowed Collateral Reduction Amount", "crypto-loan/reduce-max-collateral-amt.mdx", "orderId", 1 },
    { "bybit_crypto_loan_ongoing_orders", "GET", "/v5/crypto-loan/ongoing-orders", "Get Unpaid Loans", "crypto-loan/unpaid-loan-order.mdx", "", 1 },
    { "bybit_crypto_loan_repay", "POST", "/v5/crypto-loan/repay", "Repay", "crypto-loan/repay.mdx", "orderId, amount", 1 },
    { "bybit_crypto_loan_repayment_history", "GET", "/v5/crypto-loan/repayment-history", "Get Loan Repayment History", "crypto-loan/repay-transaction.mdx", "", 1 },
    { "bybit_dca_close_bot", "POST", "/v5/dca/close-bot", "Close DCA Bot", "bot/dca/close.mdx", "bot_id, close_mode", 1 },
    { "bybit_dca_create_bot", "POST", "/v5/dca/create-bot", "Create DCA Bot", "bot/dca/create.mdx", "parameters", 1 },
    { "bybit_earn_advance_double_win_leverage", "GET", "/v5/earn/advance/double-win-leverage", "Get Custom Product Quote", "finance/advanced-earn/double-win/leverage.mdx", "productId, initialPrice, lowerPrice, upperPrice", 1 },
    { "bybit_earn_advance_get_redeem_est_amount_list", "GET", "/v5/earn/advance/get-redeem-est-amount-list", "Get Redeem Estimated Amount", "finance/advanced-earn/smart-lvg/est-redeem.mdx", "category, positionIds", 1 },
    { "bybit_earn_advance_order", "GET", "/v5/earn/advance/order", "Get Order Info", "finance/advanced-earn/dual-asset/order.mdx", "category", 1 },
    { "bybit_earn_advance_place_order", "POST", "/v5/earn/advance/place-order", "Place Order", "finance/advanced-earn/dual-asset/create-order.mdx", "category, productId, orderType, amount, accountType, coin, orderLinkId, dualAssetsExtra", 1 },
    { "bybit_earn_advance_position", "GET", "/v5/earn/advance/position", "Get Position Info", "finance/advanced-earn/dual-asset/position.mdx", "category", 1 },
    { "bybit_earn_advance_product", "GET", "/v5/earn/advance/product", "Get Product Info", "finance/advanced-earn/dual-asset/product-info.mdx", "category", 0 },
    { "bybit_earn_advance_product_extra_info", "GET", "/v5/earn/advance/product-extra-info", "Get Product Quote", "finance/advanced-earn/dual-asset/product-quote.mdx", "productId, category", 0 },
    { "bybit_earn_apr_history", "GET", "/v5/earn/apr-history", "Get APR History", "finance/earn/easy-onchain/apr-history.mdx", "category, productId", 0 },
    { "bybit_earn_coupons", "GET", "/v5/earn/coupons", "Get Coupon List", "finance/earn/easy-onchain/coupons.mdx", "category", 1 },
    { "bybit_earn_fixed_term_order", "GET", "/v5/earn/fixed-term/order", "Get Order List", "finance/earn/fixed-saving/order.mdx", "", 1 },
    { "bybit_earn_fixed_term_place_order", "POST", "/v5/earn/fixed-term/place-order", "Place Order", "finance/earn/fixed-saving/place-order.mdx", "productId, category, coin, amount, accountType, orderLinkId", 1 },
    { "bybit_earn_fixed_term_position", "GET", "/v5/earn/fixed-term/position", "Get Position Info", "finance/earn/fixed-saving/position.mdx", "", 1 },
    { "bybit_earn_fixed_term_position_auto_invest", "POST", "/v5/earn/fixed-term/position/auto-invest", "Set Auto-Invest", "finance/earn/fixed-saving/set-auto-invest.mdx", "productId, category, positionId, status", 1 },
    { "bybit_earn_fixed_term_product", "GET", "/v5/earn/fixed-term/product", "Get Product Info", "finance/earn/fixed-saving/product.mdx", "", 1 },
    { "bybit_earn_fixed_term_redeem", "POST", "/v5/earn/fixed-term/redeem", "Redeem", "finance/earn/fixed-saving/redeem.mdx", "productId, category, positionId", 1 },
    { "bybit_earn_flexible_saving_auto_savings_get", "GET", "/v5/earn/flexible-saving/auto-savings", "Get/Set Auto Savings Settings", "finance/earn/flexible-saving/auto-savings.mdx", "", 1 },
    { "bybit_earn_flexible_saving_auto_savings_post", "POST", "/v5/earn/flexible-saving/auto-savings", "Get/Set Auto Savings Settings", "finance/earn/flexible-saving/auto-savings.mdx", "", 1 },
    { "bybit_earn_hold_to_earn_product", "GET", "/v5/earn/hold-to-earn/product", "Get Airdrop Products", "finance/earn/hold-to-earn/product.mdx", "", 0 },
    { "bybit_earn_hold_to_earn_yield_history", "GET", "/v5/earn/hold-to-earn/yield-history", "Get Airdrop Daily PnL Records", "finance/earn/hold-to-earn/yield-history.mdx", "limit", 1 },
    { "bybit_earn_hourly_yield", "GET", "/v5/earn/hourly-yield", "Get Hourly Yield History", "finance/earn/easy-onchain/hourly-yield.mdx", "category", 1 },
    { "bybit_earn_liquidity_mining_add_liquidity", "POST", "/v5/earn/liquidity-mining/add-liquidity", "Add Liquidity", "finance/advanced-earn/liquidity-mining/add-liquidity.mdx", "productId, orderLinkId", 1 },
    { "bybit_earn_liquidity_mining_add_margin", "POST", "/v5/earn/liquidity-mining/add-margin", "Add Margin", "finance/advanced-earn/liquidity-mining/add-margin.mdx", "productId, orderLinkId, positionId, amount, quoteAccountType", 1 },
    { "bybit_earn_liquidity_mining_claim_interest", "POST", "/v5/earn/liquidity-mining/claim-interest", "Claim Interest", "finance/advanced-earn/liquidity-mining/claim-interest.mdx", "productId", 1 },
    { "bybit_earn_liquidity_mining_liquidation_records", "GET", "/v5/earn/liquidity-mining/liquidation-records", "Get Liquidation Records", "finance/advanced-earn/liquidity-mining/liquidation-records.mdx", "", 1 },
    { "bybit_earn_liquidity_mining_order", "GET", "/v5/earn/liquidity-mining/order", "Get Order Info", "finance/advanced-earn/liquidity-mining/order.mdx", "", 1 },
    { "bybit_earn_liquidity_mining_position", "GET", "/v5/earn/liquidity-mining/position", "Get Position Info", "finance/advanced-earn/liquidity-mining/position.mdx", "", 1 },
    { "bybit_earn_liquidity_mining_product", "GET", "/v5/earn/liquidity-mining/product", "Get Product Info", "finance/advanced-earn/liquidity-mining/product-info.mdx", "", 0 },
    { "bybit_earn_liquidity_mining_reinvest", "POST", "/v5/earn/liquidity-mining/reinvest", "Reinvest", "finance/advanced-earn/liquidity-mining/reinvest.mdx", "productId, orderLinkId, positionId", 1 },
    { "bybit_earn_liquidity_mining_remove_liquidity", "POST", "/v5/earn/liquidity-mining/remove-liquidity", "Remove Liquidity", "finance/advanced-earn/liquidity-mining/remove-liquidity.mdx", "productId, orderLinkId, positionId", 1 },
    { "bybit_earn_liquidity_mining_yield_records", "GET", "/v5/earn/liquidity-mining/yield-records", "Get Yield Records", "finance/advanced-earn/liquidity-mining/yield-records.mdx", "", 1 },
    { "bybit_earn_order", "GET", "/v5/earn/order", "Get Stake/Redeem Order History", "finance/earn/easy-onchain/order-history.mdx", "category", 1 },
    { "bybit_earn_place_order", "POST", "/v5/earn/place-order", "Stake / Redeem", "finance/earn/easy-onchain/create-order.mdx", "category, orderType, accountType, amount, coin, productId, orderLinkId", 1 },
    { "bybit_earn_position", "GET", "/v5/earn/position", "Get Staked Position", "finance/earn/easy-onchain/position.mdx", "category", 1 },
    { "bybit_earn_position_modify", "POST", "/v5/earn/position/modify", "Modify Position", "finance/earn/easy-onchain/modify-position.mdx", "category, productId, positionId, autoReinvest", 1 },
    { "bybit_earn_product", "GET", "/v5/earn/product", "Get Product Info", "finance/earn/easy-onchain/product-info.mdx", "category", 0 },
    { "bybit_earn_pwm_asset_manager_all_funds", "GET", "/v5/earn/pwm/asset-manager/all-funds", "Get All Funds", "finance/pwm/asset-manager/all-funds.mdx", "", 1 },
    { "bybit_earn_pwm_asset_manager_all_order", "GET", "/v5/earn/pwm/asset-manager/all-order", "Get All Fund Orders", "finance/pwm/asset-manager/all-order.mdx", "", 1 },
    { "bybit_earn_pwm_asset_manager_create_fund", "POST", "/v5/earn/pwm/asset-manager/create-fund", "Create Fund (Pending Subscription)", "finance/pwm/asset-manager/create-fund.mdx", "fundName, coin, profitShareRate, managementFeeRate, reqLinkId", 1 },
    { "bybit_earn_pwm_asset_manager_create_investment_plan", "POST", "/v5/earn/pwm/asset-manager/create-investment-plan", "Create Investment Plan", "finance/pwm/asset-manager/create-investment-plan.mdx", "accountUid, planName, planType, investmentDistribution, reqLinkId", 1 },
    { "bybit_earn_pwm_asset_manager_create_sub_account", "POST", "/v5/earn/pwm/asset-manager/create-sub-account", "Create Fund Sub-Account", "finance/pwm/asset-manager/create-sub-account.mdx", "fundId, reqLinkId", 1 },
    { "bybit_earn_pwm_asset_manager_get_investment_plan", "GET", "/v5/earn/pwm/asset-manager/get-investment-plan", "Get Investment Plans", "finance/pwm/asset-manager/get-investment-plan.mdx", "", 1 },
    { "bybit_earn_pwm_asset_manager_manage_investment_plan", "POST", "/v5/earn/pwm/asset-manager/manage-investment-plan", "Manage Investment Plan", "finance/pwm/asset-manager/manage-investment-plan.mdx", "planId, reqLinkId", 1 },
    { "bybit_earn_pwm_asset_manager_manage_order", "POST", "/v5/earn/pwm/asset-manager/manage-order", "Manage Order", "finance/pwm/asset-manager/manage-order.mdx", "orderId, action, reqLinkId", 1 },
    { "bybit_earn_pwm_asset_manager_settle_profit", "POST", "/v5/earn/pwm/asset-manager/settle-profit", "Settle Fund Profit", "finance/pwm/asset-manager/settle-profit.mdx", "fundId, reqLinkId", 1 },
    { "bybit_earn_pwm_customize_plan_create", "POST", "/v5/earn/pwm/customize-plan/create", "Create Customize Investment Plan", "finance/pwm/customize-plan/create.mdx", "products", 1 },
    { "bybit_earn_pwm_customize_plan_product", "GET", "/v5/earn/pwm/customize-plan/product", "Get Subscribable Product Info", "finance/pwm/customize-plan/product.mdx", "", 0 },
    { "bybit_earn_pwm_fund_transfer", "POST", "/v5/earn/pwm/fund-transfer", "Fund Transfer Between Sub-Accounts", "finance/pwm/fund-transfer.mdx", "transferId, fromUserId, toUserId, amount, coin", 1 },
    { "bybit_earn_pwm_investment_plan_all", "GET", "/v5/earn/pwm/investment-plan/all", "Get All Investment Plans", "finance/pwm/investment-plan/all.mdx", "", 1 },
    { "bybit_earn_pwm_investment_plan_asset_trend", "GET", "/v5/earn/pwm/investment-plan/asset-trend", "Get Asset Trend", "finance/pwm/investment-plan/asset-trend.mdx", "planId", 1 },
    { "bybit_earn_pwm_investment_plan_claim", "POST", "/v5/earn/pwm/investment-plan/claim", "Claim Withdrawable Funds", "finance/pwm/investment-plan/claim.mdx", "planId, orderLinkId", 1 },
    { "bybit_earn_pwm_investment_plan_detail", "GET", "/v5/earn/pwm/investment-plan/detail", "Get Investment Plan Detail", "finance/pwm/investment-plan/detail.mdx", "planId", 1 },
    { "bybit_earn_pwm_investment_plan_fund_nav", "GET", "/v5/earn/pwm/investment-plan/fund-nav", "Get Fund Historical NAV", "finance/pwm/investment-plan/fund-nav.mdx", "fundId", 1 },
    { "bybit_earn_pwm_investment_plan_invest_more", "POST", "/v5/earn/pwm/investment-plan/invest-more", "Invest More", "finance/pwm/investment-plan/invest-more.mdx", "planId, category, productId, amount, orderLinkId", 1 },
    { "bybit_earn_pwm_investment_plan_new_plan", "GET", "/v5/earn/pwm/investment-plan/new-plan", "Get Pending Investment Plan Detail", "finance/pwm/investment-plan/new-plan.mdx", "planId", 1 },
    { "bybit_earn_pwm_investment_plan_order", "GET", "/v5/earn/pwm/investment-plan/order", "Get Investment Plan Orders", "finance/pwm/investment-plan/order.mdx", "", 1 },
    { "bybit_earn_pwm_investment_plan_redeem", "POST", "/v5/earn/pwm/investment-plan/redeem", "Redeem", "finance/pwm/investment-plan/redeem.mdx", "planId, category, productId, orderLinkId", 1 },
    { "bybit_earn_pwm_investment_plan_subscribe", "POST", "/v5/earn/pwm/investment-plan/subscribe", "Subscribe Investment Plan", "finance/pwm/investment-plan/subscribe.mdx", "planId, orderLinkId", 1 },
    { "bybit_earn_pwm_query_fund_transfer_result", "GET", "/v5/earn/pwm/query-fund-transfer-result", "Get Fund Transfer Records", "finance/pwm/query-fund-transfer-result.mdx", "", 1 },
    { "bybit_earn_rwa_nav_chart", "GET", "/v5/earn/rwa/nav-chart", "Get NAV Chart", "finance/rwa/nav-chart.mdx", "productId", 0 },
    { "bybit_earn_rwa_order", "GET", "/v5/earn/rwa/order", "Get Order List", "finance/rwa/order.mdx", "", 1 },
    { "bybit_earn_rwa_place_order", "POST", "/v5/earn/rwa/place-order", "Place Order", "finance/rwa/place-order.mdx", "productId, orderType, coin, orderLinkId", 1 },
    { "bybit_earn_rwa_position", "GET", "/v5/earn/rwa/position", "Get Position List", "finance/rwa/position.mdx", "", 1 },
    { "bybit_earn_rwa_product", "GET", "/v5/earn/rwa/product", "Get Product List", "finance/rwa/product.mdx", "", 0 },
    { "bybit_earn_token_history_apr", "GET", "/v5/earn/token/history-apr", "Get History APR", "finance/earn/byusdt/history-apr.mdx", "coin, range", 0 },
    { "bybit_earn_token_hourly_yield", "GET", "/v5/earn/token/hourly-yield", "Get Hourly Yield Records", "finance/earn/byusdt/hourly-yield.mdx", "coin", 1 },
    { "bybit_earn_token_order", "GET", "/v5/earn/token/order", "Get Order List", "finance/earn/byusdt/order.mdx", "coin", 1 },
    { "bybit_earn_token_place_order", "POST", "/v5/earn/token/place-order", "Place Order", "finance/earn/byusdt/place-order.mdx", "coin, orderLinkId, orderType, amount, accountType", 1 },
    { "bybit_earn_token_position", "GET", "/v5/earn/token/position", "Get Position Info", "finance/earn/byusdt/position.mdx", "coin", 1 },
    { "bybit_earn_token_product", "GET", "/v5/earn/token/product", "Get Product Info", "finance/earn/byusdt/product.mdx", "coin", 1 },
    { "bybit_earn_token_yield", "GET", "/v5/earn/token/yield", "Get Daily Yield Records", "finance/earn/byusdt/yield.mdx", "coin", 1 },
    { "bybit_earn_yield", "GET", "/v5/earn/yield", "Get Yield History", "finance/earn/easy-onchain/yield-history.mdx", "category", 1 },
    { "bybit_event_cancel", "POST", "/v5/event/cancel", "Cancel Quote", "event/trade/cancel-quote.mdx", "", 1 },
    { "bybit_event_cancel_all", "POST", "/v5/event/cancel-all", "Cancel All Quotes", "event/trade/cancel-all.mdx", "symbol", 1 },
    { "bybit_event_instruments_info", "GET", "/v5/event/instruments-info", "Get Instrument Info", "event/market/instrument-info.mdx", "", 0 },
    { "bybit_event_order_list", "GET", "/v5/event/order-list", "Get Event Contract Order History", "event/trade/order-list.mdx", "", 1 },
    { "bybit_event_order_realtime", "GET", "/v5/event/order-realtime", "Get Event Contract Active Orders", "event/trade/open-order.mdx", "", 1 },
    { "bybit_event_orderbook", "GET", "/v5/event/orderbook", "Get Orderbook", "event/market/orderbook.mdx", "symbol", 0 },
    { "bybit_event_positions", "GET", "/v5/event/positions", "Get Event Contract Position Info", "event/trade/position.mdx", "", 1 },
    { "bybit_event_quotes", "POST", "/v5/event/quotes", "Submit Quote", "event/trade/submit-quote.mdx", "symbol, orderLinkId, grossPayoutRatio, amount", 1 },
    { "bybit_event_settlements", "GET", "/v5/event/settlements", "Get Event Contract Settlement Records", "event/trade/settlement.mdx", "symbol", 1 },
    { "bybit_event_trades", "GET", "/v5/event/trades", "Get Event Contract Trade History", "event/trade/execution.mdx", "symbol", 1 },
    { "bybit_execution_list", "GET", "/v5/execution/list", "Get Trade History", "order/execution.mdx", "category", 1 },
    { "bybit_fcombobot_close", "POST", "/v5/fcombobot/close", "Close Bot", "bot/futures-combo/close.mdx", "bot_id", 1 },
    { "bybit_fcombobot_create", "POST", "/v5/fcombobot/create", "Create Bot", "bot/futures-combo/create.mdx", "leverage, init_margin, adjust_position_mode, symbol_settings", 1 },
    { "bybit_fcombobot_detail", "POST", "/v5/fcombobot/detail", "Get Bot Detail", "bot/futures-combo/get-detail.mdx", "bot_id", 1 },
    { "bybit_fcombobot_getlimit", "POST", "/v5/fcombobot/getlimit", "Get Bot Parameter Limit", "bot/futures-combo/get-limit.mdx", "leverage, init_margin, adjust_position_mode, symbol_settings", 1 },
    { "bybit_fgridbot_close", "POST", "/v5/fgridbot/close", "Close Grid Bot", "bot/futures-grid/close.mdx", "bot_id", 1 },
    { "bybit_fgridbot_create", "POST", "/v5/fgridbot/create", "Create Grid Bot", "bot/futures-grid/create.mdx", "symbol, grid_mode, min_price, max_price, cell_number, leverage, grid_type, total_investment", 1 },
    { "bybit_fgridbot_detail", "POST", "/v5/fgridbot/detail", "Get Grid Bot Detail", "bot/futures-grid/get-detail.mdx", "bot_id", 1 },
    { "bybit_fgridbot_validate", "POST", "/v5/fgridbot/validate", "Validate Grid Input", "bot/futures-grid/validate-input.mdx", "symbol, cell_number, min_price, max_price, leverage, grid_type, grid_mode", 1 },
    { "bybit_fht_compliance_tax_private_batch_create", "POST", "/v5/fht/compliance/tax/private/batch_create", "Batch Request Export Reports", "tax/batch-create.mdx", "startTime, endTime, items", 1 },
    { "bybit_fht_compliance_tax_private_batch_query", "GET", "/v5/fht/compliance/tax/private/batch_query", "Get Batch Export Report Status", "tax/batch-query.mdx", "batchId", 1 },
    { "bybit_fiat_balance_query", "GET", "/v5/fiat/balance-query", "Get Balance", "asset/fiat-convert/balance-query.mdx", "", 1 },
    { "bybit_fiat_query_coin_list", "GET", "/v5/fiat/query-coin-list", "Get Trading Pair List", "asset/fiat-convert/query-coin-list.mdx", "", 1 },
    { "bybit_fiat_query_trade_history", "GET", "/v5/fiat/query-trade-history", "Get Convert History", "asset/fiat-convert/query-trade-history.mdx", "", 1 },
    { "bybit_fiat_quote_apply", "POST", "/v5/fiat/quote-apply", "Request a Quote", "asset/fiat-convert/quote-apply.mdx", "fromCoin, fromCoinType, toCoin, toCoinType, requestAmount", 1 },
    { "bybit_fiat_reference_price", "GET", "/v5/fiat/reference-price", "Get Reference Price", "asset/fiat-convert/reference-price.mdx", "symbol", 1 },
    { "bybit_fiat_trade_execute", "POST", "/v5/fiat/trade-execute", "Confirm a Quote", "asset/fiat-convert/confirm-quote.mdx", "quoteTxId, subUserId", 1 },
    { "bybit_fiat_trade_query", "GET", "/v5/fiat/trade-query", "Get Convert Status", "asset/fiat-convert/query-trade.mdx", "", 1 },
    { "bybit_file_get_file_upload_sign", "POST", "/v5/file/get-file-upload-sign", "Get File Upload Sign", "file/file-upload-sign.mdx", "fileType, fileMd5, fileLen, fileName, fileMimeType", 1 },
    { "bybit_file_report_file_upload", "POST", "/v5/file/report-file-upload", "Report File Upload", "file/report-file-upload.mdx", "resourceId", 1 },
    { "bybit_fmartingalebot_close", "POST", "/v5/fmartingalebot/close", "Close Martingale Bot", "bot/futures-martingale/close.mdx", "bot_id", 1 },
    { "bybit_fmartingalebot_create", "POST", "/v5/fmartingalebot/create", "Create Martingale Bot", "bot/futures-martingale/create.mdx", "symbol, martingale_mode, leverage, price_float_percent, add_position_percent, add_position_num, init_margin, round_tp_percent", 1 },
    { "bybit_fmartingalebot_detail", "POST", "/v5/fmartingalebot/detail", "Get Martingale Bot Detail", "bot/futures-martingale/get-detail.mdx", "bot_id", 1 },
    { "bybit_fmartingalebot_getlimit", "POST", "/v5/fmartingalebot/getlimit", "Get Bot Parameter Limit", "bot/futures-martingale/get-limit.mdx", "symbol, martingale_mode, leverage", 1 },
    { "bybit_grid_close_grid", "POST", "/v5/grid/close-grid", "Close Grid Bot", "bot/spot-grid/close.mdx", "grid_id, close_mode", 1 },
    { "bybit_grid_create_grid", "POST", "/v5/grid/create-grid", "Create Grid Bot", "bot/spot-grid/create.mdx", "symbol, max_price, min_price, cell_number", 1 },
    { "bybit_grid_query_grid_detail", "POST", "/v5/grid/query-grid-detail", "Get Grid Bot Detail", "bot/spot-grid/get-detail.mdx", "grid_id", 1 },
    { "bybit_grid_validate_input", "POST", "/v5/grid/validate-input", "Validate Grid Input", "bot/spot-grid/validate-input.mdx", "symbol, cell_number, min_price, max_price", 0 },
    { "bybit_ins_loan_association_uid", "POST", "/v5/ins-loan/association-uid", "Bind Or Unbind UID", "otc/bind-uid.mdx", "uid, operate", 1 },
    { "bybit_ins_loan_coin_delta_amount", "GET", "/v5/ins-loan/coin-delta-amount", "Get Coin Delta Amount", "otc/coin-delta-amount.mdx", "", 1 },
    { "bybit_ins_loan_delay_liq_status", "GET", "/v5/ins-loan/delay-liq-status", "Get Delay Liquidation Status", "otc/delay-liq-status.mdx", "", 1 },
    { "bybit_ins_loan_ensure_tokens_convert", "GET", "/v5/ins-loan/ensure-tokens-convert", "Get Margin Coin Info", "otc/margin-coin-convert-info.mdx", "", 1 },
    { "bybit_ins_loan_loan_order", "GET", "/v5/ins-loan/loan-order", "Get Loan Orders", "otc/loan-info.mdx", "", 1 },
    { "bybit_ins_loan_ltv_convert", "GET", "/v5/ins-loan/ltv-convert", "Get LTV", "otc/ltv-convert.mdx", "", 1 },
    { "bybit_ins_loan_product_infos", "GET", "/v5/ins-loan/product-infos", "Get Product Info", "otc/margin-product-info.mdx", "", 1 },
    { "bybit_ins_loan_repaid_history", "GET", "/v5/ins-loan/repaid-history", "Get Repayment Orders", "otc/repay-info.mdx", "", 1 },
    { "bybit_ins_loan_repay_loan", "POST", "/v5/ins-loan/repay-loan", "Repay", "otc/repay.mdx", "token, quantity", 1 },
    { "bybit_ins_ip_changelog", "GET", "/v5/ins/ip/changelog", "Get Institution IP Change Log", "institution/ip-changelog.mdx", "", 1 },
    { "bybit_ins_whitelist_ip", "GET", "/v5/ins/whitelist/ip", "Get Institution Whitelist IP", "institution/whitelist-ip.mdx", "", 1 },
    { "bybit_market_account_ratio", "GET", "/v5/market/account-ratio", "Get Long Short Ratio", "market/long-short-ratio.mdx", "category, symbol, period", 0 },
    { "bybit_market_adlAlert", "GET", "/v5/market/adlAlert", "Get ADL Alert", "market/adl-alert.mdx", "", 0 },
    { "bybit_market_corporate_action", "GET", "/v5/market/corporate-action", "Query Corporate Action", "market/corporate-action.mdx", "", 0 },
    { "bybit_market_delivery_price", "GET", "/v5/market/delivery-price", "Get Delivery Price", "market/delivery-price.mdx", "category", 0 },
    { "bybit_market_fee_group_info", "GET", "/v5/market/fee-group-info", "Get Fee Group Structure", "market/fee-group-info.mdx", "productType", 0 },
    { "bybit_market_full_orderbook", "GET", "/v5/market/full_orderbook", "Get Full Depth Orderbook", "market/full-ob.mdx", "category, symbol", 0 },
    { "bybit_market_funding_history", "GET", "/v5/market/funding/history", "Get Funding Rate History", "market/history-fund-rate.mdx", "category, symbol", 0 },
    { "bybit_market_historical_volatility", "GET", "/v5/market/historical-volatility", "Get Historical Volatility", "market/iv.mdx", "category", 0 },
    { "bybit_market_index_price_components", "GET", "/v5/market/index-price-components", "TradFi Integration", "tradfi-integration.mdx", "agree", 0 },
    { "bybit_market_index_price_kline", "GET", "/v5/market/index-price-kline", "Get Index Price Kline", "market/index-kline.mdx", "symbol, interval", 0 },
    { "bybit_market_instrument_summary", "GET", "/v5/market/instrument-summary", "Get Instrument Summary", "market/instrument-summary.mdx", "category", 0 },
    { "bybit_market_instruments_info", "GET", "/v5/market/instruments-info", "TradFi Integration", "tradfi-integration.mdx", "agree", 0 },
    { "bybit_market_insurance", "GET", "/v5/market/insurance", "Get Insurance Pool", "market/insurance.mdx", "", 0 },
    { "bybit_market_kline", "GET", "/v5/market/kline", "Get Kline", "market/kline.mdx", "symbol, interval", 0 },
    { "bybit_market_mark_price_kline", "GET", "/v5/market/mark-price-kline", "Get Mark Price Kline", "market/mark-kline.mdx", "symbol, interval", 0 },
    { "bybit_market_new_delivery_price", "GET", "/v5/market/new-delivery-price", "Get New Delivery Price", "market/new-delivery-price.mdx", "category, baseCoin", 0 },
    { "bybit_market_open_interest", "GET", "/v5/market/open-interest", "Get Open Interest", "market/open-interest.mdx", "category, symbol, intervalTime", 0 },
    { "bybit_market_option_base_coins", "GET", "/v5/market/option-base-coins", "TradFi Integration", "tradfi-integration.mdx", "agree", 0 },
    { "bybit_market_orderbook", "GET", "/v5/market/orderbook", "Get Orderbook", "market/orderbook.mdx", "category, symbol", 0 },
    { "bybit_market_premium_index_price_kline", "GET", "/v5/market/premium-index-price-kline", "Get Premium Index Price Kline", "market/premium-index-kline.mdx", "symbol, interval", 0 },
    { "bybit_market_price_limit", "GET", "/v5/market/price-limit", "Get Order Price Limit", "market/order-price-limit.mdx", "symbol", 0 },
    { "bybit_market_recent_trade", "GET", "/v5/market/recent-trade", "Get Recent Public Trades", "market/recent-trade.mdx", "category", 0 },
    { "bybit_market_risk_limit", "GET", "/v5/market/risk-limit", "Get Risk Limit", "market/risk-limit.mdx", "category", 0 },
    { "bybit_market_rpi_orderbook", "GET", "/v5/market/rpi_orderbook", "Get RPI Orderbook", "market/rpi-orderbook.mdx", "symbol, limit", 0 },
    { "bybit_market_tickers", "GET", "/v5/market/tickers", "Get Tickers", "market/tickers.mdx", "category", 0 },
    { "bybit_market_time", "GET", "/v5/market/time", "Get Bybit Server Time", "market/time.mdx", "", 0 },
    { "bybit_order_amend", "POST", "/v5/order/amend", "Amend Order", "order/amend-order.mdx", "category, symbol", 1 },
    { "bybit_order_amend_batch", "POST", "/v5/order/amend-batch", "Batch Amend Order", "order/batch-amend.mdx", "category, request", 1 },
    { "bybit_order_cancel", "POST", "/v5/order/cancel", "Cancel Order", "order/cancel-order.mdx", "category, symbol", 1 },
    { "bybit_order_cancel_all", "POST", "/v5/order/cancel-all", "Cancel All Orders", "order/cancel-all.mdx", "category", 1 },
    { "bybit_order_cancel_batch", "POST", "/v5/order/cancel-batch", "Batch Cancel Order", "order/batch-cancel.mdx", "category, request", 1 },
    { "bybit_order_create", "POST", "/v5/order/create", "How To Start Copy Trading", "copytrade.mdx", "", 1 },
    { "bybit_order_create_batch", "POST", "/v5/order/create-batch", "Batch Place Order", "order/batch-place.mdx", "category, request", 1 },
    { "bybit_order_disconnected_cancel_all", "POST", "/v5/order/disconnected-cancel-all", "Set Disconnect Cancel All", "order/dcp.mdx", "timeWindow", 1 },
    { "bybit_order_history", "GET", "/v5/order/history", "Get Order History", "order/order-list.mdx", "category", 1 },
    { "bybit_order_pre_check", "POST", "/v5/order/pre-check", "Pre Check Order", "order/pre-check-order.mdx", "", 1 },
    { "bybit_order_realtime", "GET", "/v5/order/realtime", "Integration Guidance", "guide.mdx", "", 1 },
    { "bybit_order_spot_borrow_check", "GET", "/v5/order/spot-borrow-check", "Get Borrow Quota (Spot)", "order/spot-borrow-quota.mdx", "category, symbol, side", 1 },
    { "bybit_position_add_margin", "POST", "/v5/position/add-margin", "Add Or Reduce Margin", "position/manual-add-margin.mdx", "category, symbol, margin", 1 },
    { "bybit_position_closed_pnl", "GET", "/v5/position/closed-pnl", "Get Closed PnL", "position/close-pnl.mdx", "category", 1 },
    { "bybit_position_confirm_pending_mmr", "POST", "/v5/position/confirm-pending-mmr", "Confirm New Risk Limit", "position/confirm-mmr.mdx", "category, symbol", 1 },
    { "bybit_position_get_closed_positions", "GET", "/v5/position/get-closed-positions", "Get Closed Options Positions", "position/close-position.mdx", "category", 1 },
    { "bybit_position_list", "GET", "/v5/position/list", "Get Position Info", "position/position.mdx", "category", 1 },
    { "bybit_position_move_history", "GET", "/v5/position/move-history", "Get Move Position History", "position/move-position-history.mdx", "", 1 },
    { "bybit_position_move_positions", "POST", "/v5/position/move-positions", "Move Position", "position/move-position.mdx", "fromUid, toUid, list", 1 },
    { "bybit_position_set_auto_add_margin", "POST", "/v5/position/set-auto-add-margin", "Set Auto Add Margin", "position/auto-add-margin.mdx", "category, symbol, autoAddMargin", 1 },
    { "bybit_position_set_leverage", "POST", "/v5/position/set-leverage", "Set Leverage", "position/leverage.mdx", "category, symbol, buyLeverage, sellLeverage", 1 },
    { "bybit_position_switch_mode", "POST", "/v5/position/switch-mode", "Switch Position Mode", "position/position-mode.mdx", "category, mode", 1 },
    { "bybit_position_symbol_info", "GET", "/v5/position/symbol-info", "Get Futures Leverage", "position/batch-lvg.mdx", "category", 1 },
    { "bybit_position_trading_stop", "POST", "/v5/position/trading-stop", "Set Trading Stop", "position/trading-stop.mdx", "category, symbol, tpslMode, positionIdx", 1 },
    { "bybit_pre_upgrade_account_transaction_log", "GET", "/v5/pre-upgrade/account/transaction-log", "Get Pre-upgrade Transaction Log", "pre-upgrade/transaction-log.mdx", "category", 1 },
    { "bybit_pre_upgrade_asset_delivery_record", "GET", "/v5/pre-upgrade/asset/delivery-record", "Get Pre-upgrade Delivery Record", "pre-upgrade/delivery.mdx", "category", 1 },
    { "bybit_pre_upgrade_asset_settlement_record", "GET", "/v5/pre-upgrade/asset/settlement-record", "Get Pre-upgrade USDC Session Settlement", "pre-upgrade/settlement.mdx", "category", 1 },
    { "bybit_pre_upgrade_execution_list", "GET", "/v5/pre-upgrade/execution/list", "Get Pre-upgrade Trade History", "pre-upgrade/execution.mdx", "category", 1 },
    { "bybit_pre_upgrade_order_history", "GET", "/v5/pre-upgrade/order/history", "Get Pre-upgrade Order History", "pre-upgrade/order-list.mdx", "category", 1 },
    { "bybit_pre_upgrade_position_closed_pnl", "GET", "/v5/pre-upgrade/position/closed-pnl", "Get Pre-upgrade Closed PnL", "pre-upgrade/close-pnl.mdx", "category, symbol", 1 },
    { "bybit_referral_campaign_rewards", "POST", "/v5/referral/campaign/rewards", "Get Referral Campaign Rewards", "referral/referral-campaign-rewards.mdx", "", 1 },
    { "bybit_referral_commission_records", "POST", "/v5/referral/commission/records", "Get Referral Commission Records", "referral/referral-commission-records.mdx", "", 1 },
    { "bybit_referral_user_identity_profile", "POST", "/v5/referral/user/identity-profile", "Get Referral User Identity Profile", "referral/referral-user-identity-profile.mdx", "", 1 },
    { "bybit_referral_user_invitations", "POST", "/v5/referral/user/invitations", "Get Referral User Invitations", "referral/referral-user-invitations.mdx", "", 1 },
    { "bybit_rfq_accept_other_quote", "POST", "/v5/rfq/accept-other-quote", "Accept non-LP Quote", "rfq/trade/accept-other-quote.mdx", "rfqId", 1 },
    { "bybit_rfq_cancel_all_quotes", "POST", "/v5/rfq/cancel-all-quotes", "Cancel All Quotes", "rfq/trade/cancel-all-quotes.mdx", "", 1 },
    { "bybit_rfq_cancel_all_rfq", "POST", "/v5/rfq/cancel-all-rfq", "Cancel All RFQs", "rfq/trade/cancel-all-rfq.mdx", "", 1 },
    { "bybit_rfq_cancel_quote", "POST", "/v5/rfq/cancel-quote", "Cancel Quote", "rfq/trade/cancel-quote.mdx", "", 1 },
    { "bybit_rfq_cancel_rfq", "POST", "/v5/rfq/cancel-rfq", "Cancel RFQ", "rfq/trade/cancel-rfq.mdx", "", 1 },
    { "bybit_rfq_config", "GET", "/v5/rfq/config", "Get RFQ Configuration", "rfq/trade/rfq-config.mdx", "", 1 },
    { "bybit_rfq_create_quote", "POST", "/v5/rfq/create-quote", "Create Quote", "rfq/trade/create-quote.mdx", "rfqId", 1 },
    { "bybit_rfq_create_rfq", "POST", "/v5/rfq/create-rfq", "Create RFQ", "rfq/trade/create-rfq.mdx", "counterparties, list", 1 },
    { "bybit_rfq_execute_quote", "POST", "/v5/rfq/execute-quote", "Execute Quote", "rfq/trade/execute-quote.mdx", "rfqId, quoteId, quoteSide", 1 },
    { "bybit_rfq_public_trades", "GET", "/v5/rfq/public-trades", "Get Public Trades", "rfq/trade/public-trades.mdx", "", 1 },
    { "bybit_rfq_quote_list", "GET", "/v5/rfq/quote-list", "Get Quotes", "rfq/trade/quote-list.mdx", "", 1 },
    { "bybit_rfq_quote_realtime", "GET", "/v5/rfq/quote-realtime", "Get Quotes (real-time)", "rfq/trade/quote-realtime.mdx", "", 1 },
    { "bybit_rfq_rfq_detail_list", "GET", "/v5/rfq/rfq-detail-list", "Get RFQ Details", "rfq/trade/rfq-detail-list.mdx", "", 1 },
    { "bybit_rfq_rfq_list", "GET", "/v5/rfq/rfq-list", "Get RFQs", "rfq/trade/rfq-list.mdx", "", 1 },
    { "bybit_rfq_rfq_realtime", "GET", "/v5/rfq/rfq-realtime", "Get RFQs (real-time)", "rfq/trade/rfq-realtime.mdx", "", 1 },
    { "bybit_rfq_trade_list", "GET", "/v5/rfq/trade-list", "Get Trade History", "rfq/trade/trade-list.mdx", "", 1 },
    { "bybit_rwa_stocks_convert_detail", "GET", "/v5/rwa/stocks/convert/detail", "Get Convert Detail", "stocks/convert-detail.mdx", "", 1 },
    { "bybit_rwa_stocks_convert_list", "GET", "/v5/rwa/stocks/convert/list", "Get Convert List", "stocks/convert-list.mdx", "", 1 },
    { "bybit_rwa_stocks_convert_submit", "POST", "/v5/rwa/stocks/convert/submit", "Submit Convert", "stocks/convert-submit.mdx", "convertType, symbol, inputAmount, frontMultiplier, requestId, flow", 1 },
    { "bybit_rwa_stocks_market_getMultiplierList", "GET", "/v5/rwa/stocks/market/getMultiplierList", "Get Multiplier List", "stocks/multiplier-list.mdx", "current, pageSize", 1 },
    { "bybit_rwa_stocks_market_session", "GET", "/v5/rwa/stocks/market/session", "Get Market Session", "stocks/market-session.mdx", "", 1 },
    { "bybit_rwa_stocks_order", "POST", "/v5/rwa/stocks/order", "Place Stock Order", "stocks/place-order.mdx", "symbol, quoteToken, side, type, timeInForce, orderTime, requestId", 1 },
    { "bybit_rwa_stocks_order_cancel", "POST", "/v5/rwa/stocks/order/cancel", "Cancel Stock Order", "stocks/cancel-order.mdx", "orderNo", 1 },
    { "bybit_rwa_stocks_order_detail", "GET", "/v5/rwa/stocks/order/detail", "Get Stock Order Detail", "stocks/order-detail.mdx", "", 1 },
    { "bybit_rwa_stocks_positions", "GET", "/v5/rwa/stocks/positions", "Get Stock Positions", "stocks/positions.mdx", "", 1 },
    { "bybit_spot_lever_token_info", "GET", "/v5/spot-lever-token/info", "Get Leverage Token Info", "lt/leverage-token-info.mdx", "", 0 },
    { "bybit_spot_lever_token_order_record", "GET", "/v5/spot-lever-token/order-record", "Get Purchase/Redemption Records", "lt/order-record.mdx", "", 1 },
    { "bybit_spot_lever_token_purchase", "POST", "/v5/spot-lever-token/purchase", "Purchase", "lt/purchase.mdx", "ltCoin, ltAmount", 1 },
    { "bybit_spot_lever_token_redeem", "POST", "/v5/spot-lever-token/redeem", "Redeem", "lt/redeem.mdx", "ltCoin", 1 },
    { "bybit_spot_lever_token_reference", "GET", "/v5/spot-lever-token/reference", "Get Leveraged Token Market", "lt/leverage-token-reference.mdx", "ltCoin", 0 },
    { "bybit_spot_margin_trade_coinstate", "GET", "/v5/spot-margin-trade/coinstate", "Get Coin State", "spot-margin-uta/coinstate.mdx", "", 1 },
    { "bybit_spot_margin_trade_collateral", "GET", "/v5/spot-margin-trade/collateral", "Get Tiered Collateral Ratio", "spot-margin-uta/tier-collateral-ratio.mdx", "", 0 },
    { "bybit_spot_margin_trade_currency_data", "GET", "/v5/spot-margin-trade/currency-data", "Get Currency Data", "spot-margin-uta/currency-data.mdx", "", 1 },
    { "bybit_spot_margin_trade_data", "GET", "/v5/spot-margin-trade/data", "Get VIP Margin Data", "spot-margin-uta/vip-margin.mdx", "", 1 },
    { "bybit_spot_margin_trade_fixed_available_inventory", "GET", "/v5/spot-margin-trade/fixed-available-inventory", "Get Fixed-Rate Available Inventory", "spot-margin-uta/fixed-available-inventory.mdx", "currency, term, annualRate", 1 },
    { "bybit_spot_margin_trade_fixedborrow", "POST", "/v5/spot-margin-trade/fixedborrow", "Fixed-Rate Borrow", "spot-margin-uta/fixedborrow.mdx", "orderCurrency, orderAmount, annualRate, term", 1 },
    { "bybit_spot_margin_trade_fixedborrow_contract_info", "GET", "/v5/spot-margin-trade/fixedborrow-contract-info", "Get Fixed-Rate Borrow Contract Info", "spot-margin-uta/fixedborrow-contract-info.mdx", "", 1 },
    { "bybit_spot_margin_trade_fixedborrow_interest_accrued", "GET", "/v5/spot-margin-trade/fixedborrow-interest-accrued", "Query Fixed-Rate Borrow Penalty Interest", "spot-margin-uta/fixedborrow-interest-accrued.mdx", "", 1 },
    { "bybit_spot_margin_trade_fixedborrow_order_cancel", "POST", "/v5/spot-margin-trade/fixedborrow-order-cancel", "Cancel Fixed-Rate Borrow Order", "spot-margin-uta/fixedborrow-order-cancel.mdx", "orderId", 1 },
    { "bybit_spot_margin_trade_fixedborrow_order_info", "GET", "/v5/spot-margin-trade/fixedborrow-order-info", "Get Fixed-Rate Borrow Order Info", "spot-margin-uta/fixedborrow-order-info.mdx", "", 1 },
    { "bybit_spot_margin_trade_fixedborrow_order_quote", "GET", "/v5/spot-margin-trade/fixedborrow-order-quote", "Get Fixed-Rate Borrow Order Quote", "spot-margin-uta/fixedborrow-order-quote.mdx", "orderCurrency", 1 },
    { "bybit_spot_margin_trade_fixedborrow_renew", "POST", "/v5/spot-margin-trade/fixedborrow-renew", "Renew Fixed-Rate Borrow", "spot-margin-uta/fixedborrow-renew.mdx", "loanId", 1 },
    { "bybit_spot_margin_trade_flexible_available_inventory", "GET", "/v5/spot-margin-trade/flexible-available-inventory", "Get Flexible Available Inventory", "spot-margin-uta/flexible-available-inventory.mdx", "currency", 1 },
    { "bybit_spot_margin_trade_get_auto_repay_mode", "GET", "/v5/spot-margin-trade/get-auto-repay-mode", "Get Auto Repay Mode", "spot-margin-uta/get-auto-repay-mode.mdx", "", 1 },
    { "bybit_spot_margin_trade_interest_rate_history", "GET", "/v5/spot-margin-trade/interest-rate-history", "Get Historical Interest Rate", "spot-margin-uta/historical-interest.mdx", "currency", 1 },
    { "bybit_spot_margin_trade_liability", "GET", "/v5/spot-margin-trade/liability", "Get Liability Info", "spot-margin-uta/liability.mdx", "currency", 1 },
    { "bybit_spot_margin_trade_max_borrowable", "GET", "/v5/spot-margin-trade/max-borrowable", "Get Max Borrowable Amount", "spot-margin-uta/max-borrowable.mdx", "currency", 1 },
    { "bybit_spot_margin_trade_position_tiers", "GET", "/v5/spot-margin-trade/position-tiers", "Get Position Tiers", "spot-margin-uta/position-tiers.mdx", "", 1 },
    { "bybit_spot_margin_trade_repayment_available_amount", "GET", "/v5/spot-margin-trade/repayment-available-amount", "Get Available Amount to Repay", "spot-margin-uta/repayment-available-amount.mdx", "currency", 1 },
    { "bybit_spot_margin_trade_set_auto_repay_mode", "POST", "/v5/spot-margin-trade/set-auto-repay-mode", "Set Auto Repay Mode", "spot-margin-uta/set-auto-repay-mode.mdx", "autoRepayMode", 1 },
    { "bybit_spot_margin_trade_set_leverage", "POST", "/v5/spot-margin-trade/set-leverage", "Set Leverage", "spot-margin-uta/set-leverage.mdx", "leverage", 1 },
    { "bybit_spot_margin_trade_state", "GET", "/v5/spot-margin-trade/state", "Get Status And Leverage", "spot-margin-uta/status.mdx", "", 1 },
    { "bybit_spot_margin_trade_switch_mode", "POST", "/v5/spot-margin-trade/switch-mode", "Toggle Margin Trade", "spot-margin-uta/switch-mode.mdx", "spotMarginMode", 1 },
    { "bybit_spot_x_launchpool_project_list", "GET", "/v5/spot-x/launchpool/project/list", "Get Launchpool Project List", "finance/spot-x/launchpool/launchpool-project-list.mdx", "status", 0 },
    { "bybit_spot_x_launchpool_user_activity_log", "POST", "/v5/spot-x/launchpool/user/activity-log", "Get Launchpool User Activity Log", "finance/spot-x/launchpool/launchpool-activity-log.mdx", "", 1 },
    { "bybit_spot_x_launchpool_user_current_staking", "GET", "/v5/spot-x/launchpool/user/current-staking", "Get Launchpool Current Staking", "finance/spot-x/launchpool/launchpool-current-staking.mdx", "", 1 },
    { "bybit_spot_x_launchpool_user_history", "POST", "/v5/spot-x/launchpool/user/history", "Get Launchpool User History", "finance/spot-x/launchpool/launchpool-user-history.mdx", "", 1 },
    { "bybit_spot_x_puzzle_project_list", "GET", "/v5/spot-x/puzzle/project/list", "Get Puzzle Project List", "finance/spot-x/puzzle/puzzle-project-list.mdx", "status", 0 },
    { "bybit_spot_x_token_splash_project_list", "GET", "/v5/spot-x/token-splash/project/list", "Get Token Splash Project List", "finance/spot-x/token-splash/token-splash-project-list.mdx", "status", 0 },
    { "bybit_spot_x_token_splash_user_activity_params", "GET", "/v5/spot-x/token-splash/user/activity-params", "Get Token Splash User Activity Params", "finance/spot-x/token-splash/token-splash-user-activity-params.mdx", "", 1 },
    { "bybit_spread_execution_list", "GET", "/v5/spread/execution/list", "Get Trade History", "spread/trade/trade-history.mdx", "", 1 },
    { "bybit_spread_instrument", "GET", "/v5/spread/instrument", "Get Instruments Info", "spread/market/instrument.mdx", "", 0 },
    { "bybit_spread_max_qty", "GET", "/v5/spread/max-qty", "Get Max Qty", "spread/trade/max-qty.mdx", "symbol, side, orderPrice", 1 },
    { "bybit_spread_order_amend", "POST", "/v5/spread/order/amend", "Amend Order", "spread/trade/amend-order.mdx", "symbol", 1 },
    { "bybit_spread_order_cancel", "POST", "/v5/spread/order/cancel", "Cancel Order", "spread/trade/cancel-order.mdx", "", 1 },
    { "bybit_spread_order_cancel_all", "POST", "/v5/spread/order/cancel-all", "Cancel All Orders", "spread/trade/cancel-all.mdx", "", 1 },
    { "bybit_spread_order_create", "POST", "/v5/spread/order/create", "Create Order", "spread/trade/create-order.mdx", "symbol, side, orderType, qty", 1 },
    { "bybit_spread_order_history", "GET", "/v5/spread/order/history", "Get Order History", "spread/trade/order-history.mdx", "", 1 },
    { "bybit_spread_order_realtime", "GET", "/v5/spread/order/realtime", "Get Open Orders", "spread/trade/open-order.mdx", "", 1 },
    { "bybit_spread_orderbook", "GET", "/v5/spread/orderbook", "Get Orderbook", "spread/market/orderbook.mdx", "symbol", 0 },
    { "bybit_spread_recent_trade", "GET", "/v5/spread/recent-trade", "Get Recent Public Trades", "spread/market/recent-trade.mdx", "symbol", 0 },
    { "bybit_spread_tickers", "GET", "/v5/spread/tickers", "Get Tickers", "spread/market/tickers.mdx", "symbol", 0 },
    { "bybit_strategy_create", "POST", "/v5/strategy/create", "Create Strategy Order", "strategy/create-strategy.mdx", "", 1 },
    { "bybit_strategy_list", "GET", "/v5/strategy/list", "Get Strategy List", "strategy/strategy-list.mdx", "", 1 },
    { "bybit_strategy_order_list", "GET", "/v5/strategy/order-list", "Get Strategy Order List", "strategy/order-list.mdx", "strategyId", 1 },
    { "bybit_strategy_stop", "POST", "/v5/strategy/stop", "Stop Strategy", "strategy/stop-strategy.mdx", "strategyId", 1 },
    { "bybit_system_status", "GET", "/v5/system/status", "Get System Status", "system-status.mdx", "", 0 },
    { "bybit_user_aff_customer_info", "GET", "/v5/user/aff-customer-info", "Get Affiliate User Info", "affiliate/affiliate-info.mdx", "uid", 1 },
    { "bybit_user_agreement", "POST", "/v5/user/agreement", "TradFi Integration", "tradfi-integration.mdx", "agree", 1 },
    { "bybit_user_create_demo_member", "POST", "/v5/user/create-demo-member", "Demo Trading Service", "demo.mdx", "", 1 },
    { "bybit_user_create_sub_api", "POST", "/v5/user/create-sub-api", "Create Sub UID API Key", "user/create-subuid-apikey.mdx", "subuid, readOnly, permissions", 1 },
    { "bybit_user_create_sub_member", "POST", "/v5/user/create-sub-member", "Create Sub UID", "user/create-subuid.mdx", "username, memberType", 1 },
    { "bybit_user_del_submember", "POST", "/v5/user/del-submember", "Delete Sub UID", "user/rm-subuid.mdx", "subMemberId", 1 },
    { "bybit_user_delete_api", "POST", "/v5/user/delete-api", "Delete Master API Key", "user/rm-master-apikey.mdx", "", 1 },
    { "bybit_user_delete_sub_api", "POST", "/v5/user/delete-sub-api", "Delete Sub API Key", "user/rm-sub-apikey.mdx", "", 1 },
    { "bybit_user_escrow_sub_members", "GET", "/v5/user/escrow_sub_members", "Get Fund Custodial Sub Acct", "user/fund-subuid-list.mdx", "", 1 },
    { "bybit_user_frozen_sub_member", "POST", "/v5/user/frozen-sub-member", "Freeze Sub UID", "user/froze-subuid.mdx", "subuid, frozen", 1 },
    { "bybit_user_get_member_type", "GET", "/v5/user/get-member-type", "Get UID Wallet Type", "user/wallet-type.mdx", "", 1 },
    { "bybit_user_invitation_code", "GET", "/v5/user/invitation/code", "Get Referral Code", "user/referral-code.mdx", "", 1 },
    { "bybit_user_invitation_referrals", "GET", "/v5/user/invitation/referrals", "Get Friend Referrals", "user/friend-referral.mdx", "", 1 },
    { "bybit_user_query_api", "GET", "/v5/user/query-api", "Get API Key Information", "user/apikey-info.mdx", "", 1 },
    { "bybit_user_query_sub_members", "GET", "/v5/user/query-sub-members", "Get Sub UID List (Limited)", "user/subuid-list.mdx", "", 1 },
    { "bybit_user_sub_apikeys", "GET", "/v5/user/sub-apikeys", "Get Sub Account All API Keys", "user/list-sub-apikeys.mdx", "subMemberId", 1 },
    { "bybit_user_submembers", "GET", "/v5/user/submembers", "Get Sub UID List (Unlimited)", "user/page-subuid.mdx", "", 1 },
    { "bybit_user_update_api", "POST", "/v5/user/update-api", "Modify Master API Key", "user/modify-master-apikey.mdx", "", 1 },
    { "bybit_user_update_sub_api", "POST", "/v5/user/update-sub-api", "Modify Sub API Key", "user/modify-sub-apikey.mdx", "", 1 },
};

const size_t bybit_endpoint_table_count = sizeof bybit_endpoint_table / sizeof bybit_endpoint_table[0];

bybit_err bybit_account_borrow(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[0], fields, nfields, out);
}

bybit_err bybit_account_borrow_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[1], fields, nfields, out);
}

bybit_err bybit_account_collateral_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[2], fields, nfields, out);
}

bybit_err bybit_account_demo_apply_money(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[3], fields, nfields, out);
}

bybit_err bybit_account_fee_rate(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[4], fields, nfields, out);
}

bybit_err bybit_account_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[5], fields, nfields, out);
}

bybit_err bybit_account_instruments_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[6], fields, nfields, out);
}

bybit_err bybit_account_mmp_modify(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[7], fields, nfields, out);
}

bybit_err bybit_account_mmp_reset(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[8], fields, nfields, out);
}

bybit_err bybit_account_mmp_state(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[9], fields, nfields, out);
}

bybit_err bybit_account_no_convert_repay(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[10], fields, nfields, out);
}

bybit_err bybit_account_option_asset_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[11], fields, nfields, out);
}

bybit_err bybit_account_pay_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[12], fields, nfields, out);
}

bybit_err bybit_account_query_dcp_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[13], fields, nfields, out);
}

bybit_err bybit_account_quick_repayment(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[14], fields, nfields, out);
}

bybit_err bybit_account_repay(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[15], fields, nfields, out);
}

bybit_err bybit_account_set_collateral_switch(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[16], fields, nfields, out);
}

bybit_err bybit_account_set_collateral_switch_batch(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[17], fields, nfields, out);
}

bybit_err bybit_account_set_delta_mode(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[18], fields, nfields, out);
}

bybit_err bybit_account_set_hedging_mode(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[19], fields, nfields, out);
}

bybit_err bybit_account_set_limit_px_action(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[20], fields, nfields, out);
}

bybit_err bybit_account_set_margin_mode(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[21], fields, nfields, out);
}

bybit_err bybit_account_smp_group(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[22], fields, nfields, out);
}

bybit_err bybit_account_trade_info_for_analysis(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[23], fields, nfields, out);
}

bybit_err bybit_account_transaction_log(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[24], fields, nfields, out);
}

bybit_err bybit_account_upgrade_to_uta(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[25], fields, nfields, out);
}

bybit_err bybit_account_user_setting_config(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[26], fields, nfields, out);
}

bybit_err bybit_account_wallet_balance(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[27], fields, nfields, out);
}

bybit_err bybit_account_withdrawal(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[28], fields, nfields, out);
}

bybit_err bybit_affiliate_aff_user_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[29], fields, nfields, out);
}

bybit_err bybit_affiliate_affiliate_sub_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[30], fields, nfields, out);
}

bybit_err bybit_alpha_lp_order_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[31], fields, nfields, out);
}

bybit_err bybit_alpha_lp_pay_token_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[32], fields, nfields, out);
}

bybit_err bybit_alpha_lp_pay_token_price(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[33], fields, nfields, out);
}

bybit_err bybit_alpha_lp_pool_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[34], fields, nfields, out);
}

bybit_err bybit_alpha_lp_pool_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[35], fields, nfields, out);
}

bybit_err bybit_alpha_lp_position_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[36], fields, nfields, out);
}

bybit_err bybit_alpha_lp_redeem(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[37], fields, nfields, out);
}

bybit_err bybit_alpha_lp_stake(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[38], fields, nfields, out);
}

bybit_err bybit_alpha_prediction_buy(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[39], fields, nfields, out);
}

bybit_err bybit_alpha_prediction_engine_status(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[40], fields, nfields, out);
}

bybit_err bybit_alpha_prediction_event_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[41], fields, nfields, out);
}

bybit_err bybit_alpha_prediction_order_book(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[42], fields, nfields, out);
}

bybit_err bybit_alpha_prediction_order_estimate(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[43], fields, nfields, out);
}

bybit_err bybit_alpha_prediction_order_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[44], fields, nfields, out);
}

bybit_err bybit_alpha_prediction_pay_token_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[45], fields, nfields, out);
}

bybit_err bybit_alpha_prediction_portfolio_summary(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[46], fields, nfields, out);
}

bybit_err bybit_alpha_prediction_position_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[47], fields, nfields, out);
}

bybit_err bybit_alpha_prediction_position_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[48], fields, nfields, out);
}

bybit_err bybit_alpha_prediction_price_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[49], fields, nfields, out);
}

bybit_err bybit_alpha_prediction_sell(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[50], fields, nfields, out);
}

bybit_err bybit_alpha_prediction_side_market_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[51], fields, nfields, out);
}

bybit_err bybit_alpha_prediction_sports_group_stage_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[52], fields, nfields, out);
}

bybit_err bybit_alpha_prediction_sports_match_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[53], fields, nfields, out);
}

bybit_err bybit_alpha_prediction_sports_timeline_stages(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[54], fields, nfields, out);
}

bybit_err bybit_alpha_prediction_token_price(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[55], fields, nfields, out);
}

bybit_err bybit_alpha_trade_asset_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[56], fields, nfields, out);
}

bybit_err bybit_alpha_trade_asset_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[57], fields, nfields, out);
}

bybit_err bybit_alpha_trade_biz_token_details(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[58], fields, nfields, out);
}

bybit_err bybit_alpha_trade_biz_token_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[59], fields, nfields, out);
}

bybit_err bybit_alpha_trade_biz_token_price_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[60], fields, nfields, out);
}

bybit_err bybit_alpha_trade_order_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[61], fields, nfields, out);
}

bybit_err bybit_alpha_trade_pay_token_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[62], fields, nfields, out);
}

bybit_err bybit_alpha_trade_purchase(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[63], fields, nfields, out);
}

bybit_err bybit_alpha_trade_quote(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[64], fields, nfields, out);
}

bybit_err bybit_alpha_trade_redeem(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[65], fields, nfields, out);
}

bybit_err bybit_announcements_index(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[66], fields, nfields, out);
}

bybit_err bybit_apilimit_query(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[67], fields, nfields, out);
}

bybit_err bybit_apilimit_query_all(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[68], fields, nfields, out);
}

bybit_err bybit_apilimit_query_cap(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[69], fields, nfields, out);
}

bybit_err bybit_apilimit_set(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[70], fields, nfields, out);
}

bybit_err bybit_asset_asset_overview(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[71], fields, nfields, out);
}

bybit_err bybit_asset_coin_greeks(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[72], fields, nfields, out);
}

bybit_err bybit_asset_coin_query_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[73], fields, nfields, out);
}

bybit_err bybit_asset_covert_get_quote(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[74], fields, nfields, out);
}

bybit_err bybit_asset_covert_small_balance_execute(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[75], fields, nfields, out);
}

bybit_err bybit_asset_covert_small_balance_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[76], fields, nfields, out);
}

bybit_err bybit_asset_covert_small_balance_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[77], fields, nfields, out);
}

bybit_err bybit_asset_delivery_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[78], fields, nfields, out);
}

bybit_err bybit_asset_deposit_deposit_to_account(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[79], fields, nfields, out);
}

bybit_err bybit_asset_deposit_query_address(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[80], fields, nfields, out);
}

bybit_err bybit_asset_deposit_query_internal_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[81], fields, nfields, out);
}

bybit_err bybit_asset_deposit_query_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[82], fields, nfields, out);
}

bybit_err bybit_asset_deposit_query_sub_member_address(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[83], fields, nfields, out);
}

bybit_err bybit_asset_deposit_query_sub_member_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[84], fields, nfields, out);
}

bybit_err bybit_asset_exchange_convert_execute(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[85], fields, nfields, out);
}

bybit_err bybit_asset_exchange_convert_result_query(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[86], fields, nfields, out);
}

bybit_err bybit_asset_exchange_order_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[87], fields, nfields, out);
}

bybit_err bybit_asset_exchange_query_coin_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[88], fields, nfields, out);
}

bybit_err bybit_asset_exchange_query_convert_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[89], fields, nfields, out);
}

bybit_err bybit_asset_exchange_quote_apply(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[90], fields, nfields, out);
}

bybit_err bybit_asset_fundinghistory(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[91], fields, nfields, out);
}

bybit_err bybit_asset_portfolio_margin(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[92], fields, nfields, out);
}

bybit_err bybit_asset_settlement_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[93], fields, nfields, out);
}

bybit_err bybit_asset_total_members_assets(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[94], fields, nfields, out);
}

bybit_err bybit_asset_transfer_inter_transfer(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[95], fields, nfields, out);
}

bybit_err bybit_asset_transfer_query_account_coin_balance(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[96], fields, nfields, out);
}

bybit_err bybit_asset_transfer_query_account_coins_balance(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[97], fields, nfields, out);
}

bybit_err bybit_asset_transfer_query_inter_transfer_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[98], fields, nfields, out);
}

bybit_err bybit_asset_transfer_query_sub_member_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[99], fields, nfields, out);
}

bybit_err bybit_asset_transfer_query_transfer_coin_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[100], fields, nfields, out);
}

bybit_err bybit_asset_transfer_query_universal_transfer_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[101], fields, nfields, out);
}

bybit_err bybit_asset_transfer_universal_transfer(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[102], fields, nfields, out);
}

bybit_err bybit_asset_travel_rule_deposit_submit(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[103], fields, nfields, out);
}

bybit_err bybit_asset_withdraw_cancel(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[104], fields, nfields, out);
}

bybit_err bybit_asset_withdraw_create(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[105], fields, nfields, out);
}

bybit_err bybit_asset_withdraw_query_address(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[106], fields, nfields, out);
}

bybit_err bybit_asset_withdraw_query_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[107], fields, nfields, out);
}

bybit_err bybit_asset_withdraw_vasp_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[108], fields, nfields, out);
}

bybit_err bybit_asset_withdraw_withdrawable_amount(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[109], fields, nfields, out);
}

bybit_err bybit_broker_account_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[110], fields, nfields, out);
}

bybit_err bybit_broker_apilimit_query_all(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[111], fields, nfields, out);
}

bybit_err bybit_broker_apilimit_query_cap(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[112], fields, nfields, out);
}

bybit_err bybit_broker_apilimit_set(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[113], fields, nfields, out);
}

bybit_err bybit_broker_asset_query_sub_member_deposit_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[114], fields, nfields, out);
}

bybit_err bybit_broker_award_distribute_award(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[115], fields, nfields, out);
}

bybit_err bybit_broker_award_distribution_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[116], fields, nfields, out);
}

bybit_err bybit_broker_award_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[117], fields, nfields, out);
}

bybit_err bybit_broker_earnings_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[118], fields, nfields, out);
}

bybit_err bybit_broker_ip_changelog(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[119], fields, nfields, out);
}

bybit_err bybit_broker_whitelist_ip(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[120], fields, nfields, out);
}

bybit_err bybit_card_reward_mall_item_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[121], fields, nfields, out);
}

bybit_err bybit_card_reward_point_cashback_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[122], fields, nfields, out);
}

bybit_err bybit_card_reward_points_balance(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[123], fields, nfields, out);
}

bybit_err bybit_card_reward_points_records(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[124], fields, nfields, out);
}

bybit_err bybit_card_reward_points_tier(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[125], fields, nfields, out);
}

bybit_err bybit_card_transaction_query_asset_records(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[126], fields, nfields, out);
}

bybit_err bybit_compliance_appeal_commit(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[127], fields, nfields, out);
}

bybit_err bybit_compliance_appeal_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[128], fields, nfields, out);
}

bybit_err bybit_compliance_appeal_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[129], fields, nfields, out);
}

bybit_err bybit_crypto_loan_common_adjust_ltv(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[130], fields, nfields, out);
}

bybit_err bybit_crypto_loan_common_adjustment_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[131], fields, nfields, out);
}

bybit_err bybit_crypto_loan_common_collateral_data(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[132], fields, nfields, out);
}

bybit_err bybit_crypto_loan_common_loanable_data(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[133], fields, nfields, out);
}

bybit_err bybit_crypto_loan_common_max_collateral_amount(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[134], fields, nfields, out);
}

bybit_err bybit_crypto_loan_common_max_loan(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[135], fields, nfields, out);
}

bybit_err bybit_crypto_loan_common_position(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[136], fields, nfields, out);
}

bybit_err bybit_crypto_loan_fixed_available_inventory(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[137], fields, nfields, out);
}

bybit_err bybit_crypto_loan_fixed_borrow(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[138], fields, nfields, out);
}

bybit_err bybit_crypto_loan_fixed_borrow_contract_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[139], fields, nfields, out);
}

bybit_err bybit_crypto_loan_fixed_borrow_order_cancel(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[140], fields, nfields, out);
}

bybit_err bybit_crypto_loan_fixed_borrow_order_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[141], fields, nfields, out);
}

bybit_err bybit_crypto_loan_fixed_borrow_order_quote(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[142], fields, nfields, out);
}

bybit_err bybit_crypto_loan_fixed_fully_repay(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[143], fields, nfields, out);
}

bybit_err bybit_crypto_loan_fixed_renew(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[144], fields, nfields, out);
}

bybit_err bybit_crypto_loan_fixed_renew_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[145], fields, nfields, out);
}

bybit_err bybit_crypto_loan_fixed_repay_collateral(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[146], fields, nfields, out);
}

bybit_err bybit_crypto_loan_fixed_repayment_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[147], fields, nfields, out);
}

bybit_err bybit_crypto_loan_fixed_supply(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[148], fields, nfields, out);
}

bybit_err bybit_crypto_loan_fixed_supply_contract_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[149], fields, nfields, out);
}

bybit_err bybit_crypto_loan_fixed_supply_order_cancel(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[150], fields, nfields, out);
}

bybit_err bybit_crypto_loan_fixed_supply_order_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[151], fields, nfields, out);
}

bybit_err bybit_crypto_loan_fixed_supply_order_quote(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[152], fields, nfields, out);
}

bybit_err bybit_crypto_loan_flexible_available_inventory(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[153], fields, nfields, out);
}

bybit_err bybit_crypto_loan_flexible_borrow(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[154], fields, nfields, out);
}

bybit_err bybit_crypto_loan_flexible_borrow_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[155], fields, nfields, out);
}

bybit_err bybit_crypto_loan_flexible_ongoing_coin(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[156], fields, nfields, out);
}

bybit_err bybit_crypto_loan_flexible_repay(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[157], fields, nfields, out);
}

bybit_err bybit_crypto_loan_flexible_repay_collateral(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[158], fields, nfields, out);
}

bybit_err bybit_crypto_loan_flexible_repayment_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[159], fields, nfields, out);
}

bybit_err bybit_crypto_loan_adjust_ltv(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[160], fields, nfields, out);
}

bybit_err bybit_crypto_loan_adjustment_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[161], fields, nfields, out);
}

bybit_err bybit_crypto_loan_borrow_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[162], fields, nfields, out);
}

bybit_err bybit_crypto_loan_borrowable_collateralisable_number(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[163], fields, nfields, out);
}

bybit_err bybit_crypto_loan_collateral_data(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[164], fields, nfields, out);
}

bybit_err bybit_crypto_loan_loanable_data(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[165], fields, nfields, out);
}

bybit_err bybit_crypto_loan_max_collateral_amount(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[166], fields, nfields, out);
}

bybit_err bybit_crypto_loan_ongoing_orders(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[167], fields, nfields, out);
}

bybit_err bybit_crypto_loan_repay(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[168], fields, nfields, out);
}

bybit_err bybit_crypto_loan_repayment_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[169], fields, nfields, out);
}

bybit_err bybit_dca_close_bot(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[170], fields, nfields, out);
}

bybit_err bybit_dca_create_bot(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[171], fields, nfields, out);
}

bybit_err bybit_earn_advance_double_win_leverage(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[172], fields, nfields, out);
}

bybit_err bybit_earn_advance_get_redeem_est_amount_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[173], fields, nfields, out);
}

bybit_err bybit_earn_advance_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[174], fields, nfields, out);
}

bybit_err bybit_earn_advance_place_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[175], fields, nfields, out);
}

bybit_err bybit_earn_advance_position(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[176], fields, nfields, out);
}

bybit_err bybit_earn_advance_product(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[177], fields, nfields, out);
}

bybit_err bybit_earn_advance_product_extra_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[178], fields, nfields, out);
}

bybit_err bybit_earn_apr_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[179], fields, nfields, out);
}

bybit_err bybit_earn_coupons(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[180], fields, nfields, out);
}

bybit_err bybit_earn_fixed_term_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[181], fields, nfields, out);
}

bybit_err bybit_earn_fixed_term_place_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[182], fields, nfields, out);
}

bybit_err bybit_earn_fixed_term_position(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[183], fields, nfields, out);
}

bybit_err bybit_earn_fixed_term_position_auto_invest(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[184], fields, nfields, out);
}

bybit_err bybit_earn_fixed_term_product(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[185], fields, nfields, out);
}

bybit_err bybit_earn_fixed_term_redeem(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[186], fields, nfields, out);
}

bybit_err bybit_earn_flexible_saving_auto_savings_get(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[187], fields, nfields, out);
}

bybit_err bybit_earn_flexible_saving_auto_savings_post(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[188], fields, nfields, out);
}

bybit_err bybit_earn_hold_to_earn_product(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[189], fields, nfields, out);
}

bybit_err bybit_earn_hold_to_earn_yield_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[190], fields, nfields, out);
}

bybit_err bybit_earn_hourly_yield(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[191], fields, nfields, out);
}

bybit_err bybit_earn_liquidity_mining_add_liquidity(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[192], fields, nfields, out);
}

bybit_err bybit_earn_liquidity_mining_add_margin(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[193], fields, nfields, out);
}

bybit_err bybit_earn_liquidity_mining_claim_interest(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[194], fields, nfields, out);
}

bybit_err bybit_earn_liquidity_mining_liquidation_records(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[195], fields, nfields, out);
}

bybit_err bybit_earn_liquidity_mining_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[196], fields, nfields, out);
}

bybit_err bybit_earn_liquidity_mining_position(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[197], fields, nfields, out);
}

bybit_err bybit_earn_liquidity_mining_product(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[198], fields, nfields, out);
}

bybit_err bybit_earn_liquidity_mining_reinvest(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[199], fields, nfields, out);
}

bybit_err bybit_earn_liquidity_mining_remove_liquidity(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[200], fields, nfields, out);
}

bybit_err bybit_earn_liquidity_mining_yield_records(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[201], fields, nfields, out);
}

bybit_err bybit_earn_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[202], fields, nfields, out);
}

bybit_err bybit_earn_place_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[203], fields, nfields, out);
}

bybit_err bybit_earn_position(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[204], fields, nfields, out);
}

bybit_err bybit_earn_position_modify(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[205], fields, nfields, out);
}

bybit_err bybit_earn_product(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[206], fields, nfields, out);
}

bybit_err bybit_earn_pwm_asset_manager_all_funds(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[207], fields, nfields, out);
}

bybit_err bybit_earn_pwm_asset_manager_all_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[208], fields, nfields, out);
}

bybit_err bybit_earn_pwm_asset_manager_create_fund(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[209], fields, nfields, out);
}

bybit_err bybit_earn_pwm_asset_manager_create_investment_plan(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[210], fields, nfields, out);
}

bybit_err bybit_earn_pwm_asset_manager_create_sub_account(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[211], fields, nfields, out);
}

bybit_err bybit_earn_pwm_asset_manager_get_investment_plan(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[212], fields, nfields, out);
}

bybit_err bybit_earn_pwm_asset_manager_manage_investment_plan(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[213], fields, nfields, out);
}

bybit_err bybit_earn_pwm_asset_manager_manage_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[214], fields, nfields, out);
}

bybit_err bybit_earn_pwm_asset_manager_settle_profit(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[215], fields, nfields, out);
}

bybit_err bybit_earn_pwm_customize_plan_create(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[216], fields, nfields, out);
}

bybit_err bybit_earn_pwm_customize_plan_product(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[217], fields, nfields, out);
}

bybit_err bybit_earn_pwm_fund_transfer(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[218], fields, nfields, out);
}

bybit_err bybit_earn_pwm_investment_plan_all(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[219], fields, nfields, out);
}

bybit_err bybit_earn_pwm_investment_plan_asset_trend(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[220], fields, nfields, out);
}

bybit_err bybit_earn_pwm_investment_plan_claim(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[221], fields, nfields, out);
}

bybit_err bybit_earn_pwm_investment_plan_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[222], fields, nfields, out);
}

bybit_err bybit_earn_pwm_investment_plan_fund_nav(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[223], fields, nfields, out);
}

bybit_err bybit_earn_pwm_investment_plan_invest_more(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[224], fields, nfields, out);
}

bybit_err bybit_earn_pwm_investment_plan_new_plan(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[225], fields, nfields, out);
}

bybit_err bybit_earn_pwm_investment_plan_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[226], fields, nfields, out);
}

bybit_err bybit_earn_pwm_investment_plan_redeem(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[227], fields, nfields, out);
}

bybit_err bybit_earn_pwm_investment_plan_subscribe(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[228], fields, nfields, out);
}

bybit_err bybit_earn_pwm_query_fund_transfer_result(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[229], fields, nfields, out);
}

bybit_err bybit_earn_rwa_nav_chart(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[230], fields, nfields, out);
}

bybit_err bybit_earn_rwa_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[231], fields, nfields, out);
}

bybit_err bybit_earn_rwa_place_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[232], fields, nfields, out);
}

bybit_err bybit_earn_rwa_position(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[233], fields, nfields, out);
}

bybit_err bybit_earn_rwa_product(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[234], fields, nfields, out);
}

bybit_err bybit_earn_token_history_apr(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[235], fields, nfields, out);
}

bybit_err bybit_earn_token_hourly_yield(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[236], fields, nfields, out);
}

bybit_err bybit_earn_token_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[237], fields, nfields, out);
}

bybit_err bybit_earn_token_place_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[238], fields, nfields, out);
}

bybit_err bybit_earn_token_position(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[239], fields, nfields, out);
}

bybit_err bybit_earn_token_product(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[240], fields, nfields, out);
}

bybit_err bybit_earn_token_yield(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[241], fields, nfields, out);
}

bybit_err bybit_earn_yield(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[242], fields, nfields, out);
}

bybit_err bybit_event_cancel(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[243], fields, nfields, out);
}

bybit_err bybit_event_cancel_all(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[244], fields, nfields, out);
}

bybit_err bybit_event_instruments_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[245], fields, nfields, out);
}

bybit_err bybit_event_order_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[246], fields, nfields, out);
}

bybit_err bybit_event_order_realtime(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[247], fields, nfields, out);
}

bybit_err bybit_event_orderbook(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[248], fields, nfields, out);
}

bybit_err bybit_event_positions(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[249], fields, nfields, out);
}

bybit_err bybit_event_quotes(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[250], fields, nfields, out);
}

bybit_err bybit_event_settlements(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[251], fields, nfields, out);
}

bybit_err bybit_event_trades(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[252], fields, nfields, out);
}

bybit_err bybit_execution_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[253], fields, nfields, out);
}

bybit_err bybit_fcombobot_close(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[254], fields, nfields, out);
}

bybit_err bybit_fcombobot_create(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[255], fields, nfields, out);
}

bybit_err bybit_fcombobot_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[256], fields, nfields, out);
}

bybit_err bybit_fcombobot_getlimit(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[257], fields, nfields, out);
}

bybit_err bybit_fgridbot_close(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[258], fields, nfields, out);
}

bybit_err bybit_fgridbot_create(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[259], fields, nfields, out);
}

bybit_err bybit_fgridbot_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[260], fields, nfields, out);
}

bybit_err bybit_fgridbot_validate(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[261], fields, nfields, out);
}

bybit_err bybit_fht_compliance_tax_private_batch_create(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[262], fields, nfields, out);
}

bybit_err bybit_fht_compliance_tax_private_batch_query(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[263], fields, nfields, out);
}

bybit_err bybit_fiat_balance_query(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[264], fields, nfields, out);
}

bybit_err bybit_fiat_query_coin_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[265], fields, nfields, out);
}

bybit_err bybit_fiat_query_trade_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[266], fields, nfields, out);
}

bybit_err bybit_fiat_quote_apply(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[267], fields, nfields, out);
}

bybit_err bybit_fiat_reference_price(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[268], fields, nfields, out);
}

bybit_err bybit_fiat_trade_execute(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[269], fields, nfields, out);
}

bybit_err bybit_fiat_trade_query(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[270], fields, nfields, out);
}

bybit_err bybit_file_get_file_upload_sign(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[271], fields, nfields, out);
}

bybit_err bybit_file_report_file_upload(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[272], fields, nfields, out);
}

bybit_err bybit_fmartingalebot_close(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[273], fields, nfields, out);
}

bybit_err bybit_fmartingalebot_create(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[274], fields, nfields, out);
}

bybit_err bybit_fmartingalebot_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[275], fields, nfields, out);
}

bybit_err bybit_fmartingalebot_getlimit(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[276], fields, nfields, out);
}

bybit_err bybit_grid_close_grid(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[277], fields, nfields, out);
}

bybit_err bybit_grid_create_grid(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[278], fields, nfields, out);
}

bybit_err bybit_grid_query_grid_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[279], fields, nfields, out);
}

bybit_err bybit_grid_validate_input(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[280], fields, nfields, out);
}

bybit_err bybit_ins_loan_association_uid(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[281], fields, nfields, out);
}

bybit_err bybit_ins_loan_coin_delta_amount(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[282], fields, nfields, out);
}

bybit_err bybit_ins_loan_delay_liq_status(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[283], fields, nfields, out);
}

bybit_err bybit_ins_loan_ensure_tokens_convert(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[284], fields, nfields, out);
}

bybit_err bybit_ins_loan_loan_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[285], fields, nfields, out);
}

bybit_err bybit_ins_loan_ltv_convert(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[286], fields, nfields, out);
}

bybit_err bybit_ins_loan_product_infos(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[287], fields, nfields, out);
}

bybit_err bybit_ins_loan_repaid_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[288], fields, nfields, out);
}

bybit_err bybit_ins_loan_repay_loan(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[289], fields, nfields, out);
}

bybit_err bybit_ins_ip_changelog(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[290], fields, nfields, out);
}

bybit_err bybit_ins_whitelist_ip(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[291], fields, nfields, out);
}

bybit_err bybit_market_account_ratio(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[292], fields, nfields, out);
}

bybit_err bybit_market_adlAlert(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[293], fields, nfields, out);
}

bybit_err bybit_market_corporate_action(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[294], fields, nfields, out);
}

bybit_err bybit_market_delivery_price(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[295], fields, nfields, out);
}

bybit_err bybit_market_fee_group_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[296], fields, nfields, out);
}

bybit_err bybit_market_full_orderbook(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[297], fields, nfields, out);
}

bybit_err bybit_market_funding_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[298], fields, nfields, out);
}

bybit_err bybit_market_historical_volatility(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[299], fields, nfields, out);
}

bybit_err bybit_market_index_price_components(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[300], fields, nfields, out);
}

bybit_err bybit_market_index_price_kline(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[301], fields, nfields, out);
}

bybit_err bybit_market_instrument_summary(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[302], fields, nfields, out);
}

bybit_err bybit_market_instruments_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[303], fields, nfields, out);
}

bybit_err bybit_market_insurance(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[304], fields, nfields, out);
}

bybit_err bybit_market_kline(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[305], fields, nfields, out);
}

bybit_err bybit_market_mark_price_kline(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[306], fields, nfields, out);
}

bybit_err bybit_market_new_delivery_price(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[307], fields, nfields, out);
}

bybit_err bybit_market_open_interest(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[308], fields, nfields, out);
}

bybit_err bybit_market_option_base_coins(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[309], fields, nfields, out);
}

bybit_err bybit_market_orderbook(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[310], fields, nfields, out);
}

bybit_err bybit_market_premium_index_price_kline(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[311], fields, nfields, out);
}

bybit_err bybit_market_price_limit(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[312], fields, nfields, out);
}

bybit_err bybit_market_recent_trade(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[313], fields, nfields, out);
}

bybit_err bybit_market_risk_limit(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[314], fields, nfields, out);
}

bybit_err bybit_market_rpi_orderbook(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[315], fields, nfields, out);
}

bybit_err bybit_market_tickers(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[316], fields, nfields, out);
}

bybit_err bybit_market_time(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[317], fields, nfields, out);
}

bybit_err bybit_order_amend(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[318], fields, nfields, out);
}

bybit_err bybit_order_amend_batch(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[319], fields, nfields, out);
}

bybit_err bybit_order_cancel(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[320], fields, nfields, out);
}

bybit_err bybit_order_cancel_all(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[321], fields, nfields, out);
}

bybit_err bybit_order_cancel_batch(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[322], fields, nfields, out);
}

bybit_err bybit_order_create(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[323], fields, nfields, out);
}

bybit_err bybit_order_create_batch(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[324], fields, nfields, out);
}

bybit_err bybit_order_disconnected_cancel_all(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[325], fields, nfields, out);
}

bybit_err bybit_order_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[326], fields, nfields, out);
}

bybit_err bybit_order_pre_check(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[327], fields, nfields, out);
}

bybit_err bybit_order_realtime(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[328], fields, nfields, out);
}

bybit_err bybit_order_spot_borrow_check(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[329], fields, nfields, out);
}

bybit_err bybit_position_add_margin(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[330], fields, nfields, out);
}

bybit_err bybit_position_closed_pnl(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[331], fields, nfields, out);
}

bybit_err bybit_position_confirm_pending_mmr(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[332], fields, nfields, out);
}

bybit_err bybit_position_get_closed_positions(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[333], fields, nfields, out);
}

bybit_err bybit_position_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[334], fields, nfields, out);
}

bybit_err bybit_position_move_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[335], fields, nfields, out);
}

bybit_err bybit_position_move_positions(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[336], fields, nfields, out);
}

bybit_err bybit_position_set_auto_add_margin(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[337], fields, nfields, out);
}

bybit_err bybit_position_set_leverage(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[338], fields, nfields, out);
}

bybit_err bybit_position_switch_mode(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[339], fields, nfields, out);
}

bybit_err bybit_position_symbol_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[340], fields, nfields, out);
}

bybit_err bybit_position_trading_stop(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[341], fields, nfields, out);
}

bybit_err bybit_pre_upgrade_account_transaction_log(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[342], fields, nfields, out);
}

bybit_err bybit_pre_upgrade_asset_delivery_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[343], fields, nfields, out);
}

bybit_err bybit_pre_upgrade_asset_settlement_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[344], fields, nfields, out);
}

bybit_err bybit_pre_upgrade_execution_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[345], fields, nfields, out);
}

bybit_err bybit_pre_upgrade_order_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[346], fields, nfields, out);
}

bybit_err bybit_pre_upgrade_position_closed_pnl(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[347], fields, nfields, out);
}

bybit_err bybit_referral_campaign_rewards(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[348], fields, nfields, out);
}

bybit_err bybit_referral_commission_records(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[349], fields, nfields, out);
}

bybit_err bybit_referral_user_identity_profile(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[350], fields, nfields, out);
}

bybit_err bybit_referral_user_invitations(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[351], fields, nfields, out);
}

bybit_err bybit_rfq_accept_other_quote(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[352], fields, nfields, out);
}

bybit_err bybit_rfq_cancel_all_quotes(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[353], fields, nfields, out);
}

bybit_err bybit_rfq_cancel_all_rfq(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[354], fields, nfields, out);
}

bybit_err bybit_rfq_cancel_quote(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[355], fields, nfields, out);
}

bybit_err bybit_rfq_cancel_rfq(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[356], fields, nfields, out);
}

bybit_err bybit_rfq_config(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[357], fields, nfields, out);
}

bybit_err bybit_rfq_create_quote(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[358], fields, nfields, out);
}

bybit_err bybit_rfq_create_rfq(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[359], fields, nfields, out);
}

bybit_err bybit_rfq_execute_quote(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[360], fields, nfields, out);
}

bybit_err bybit_rfq_public_trades(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[361], fields, nfields, out);
}

bybit_err bybit_rfq_quote_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[362], fields, nfields, out);
}

bybit_err bybit_rfq_quote_realtime(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[363], fields, nfields, out);
}

bybit_err bybit_rfq_rfq_detail_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[364], fields, nfields, out);
}

bybit_err bybit_rfq_rfq_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[365], fields, nfields, out);
}

bybit_err bybit_rfq_rfq_realtime(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[366], fields, nfields, out);
}

bybit_err bybit_rfq_trade_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[367], fields, nfields, out);
}

bybit_err bybit_rwa_stocks_convert_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[368], fields, nfields, out);
}

bybit_err bybit_rwa_stocks_convert_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[369], fields, nfields, out);
}

bybit_err bybit_rwa_stocks_convert_submit(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[370], fields, nfields, out);
}

bybit_err bybit_rwa_stocks_market_getMultiplierList(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[371], fields, nfields, out);
}

bybit_err bybit_rwa_stocks_market_session(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[372], fields, nfields, out);
}

bybit_err bybit_rwa_stocks_order(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[373], fields, nfields, out);
}

bybit_err bybit_rwa_stocks_order_cancel(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[374], fields, nfields, out);
}

bybit_err bybit_rwa_stocks_order_detail(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[375], fields, nfields, out);
}

bybit_err bybit_rwa_stocks_positions(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[376], fields, nfields, out);
}

bybit_err bybit_spot_lever_token_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[377], fields, nfields, out);
}

bybit_err bybit_spot_lever_token_order_record(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[378], fields, nfields, out);
}

bybit_err bybit_spot_lever_token_purchase(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[379], fields, nfields, out);
}

bybit_err bybit_spot_lever_token_redeem(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[380], fields, nfields, out);
}

bybit_err bybit_spot_lever_token_reference(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[381], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_coinstate(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[382], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_collateral(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[383], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_currency_data(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[384], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_data(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[385], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_fixed_available_inventory(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[386], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_fixedborrow(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[387], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_fixedborrow_contract_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[388], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_fixedborrow_interest_accrued(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[389], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_fixedborrow_order_cancel(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[390], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_fixedborrow_order_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[391], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_fixedborrow_order_quote(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[392], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_fixedborrow_renew(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[393], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_flexible_available_inventory(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[394], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_get_auto_repay_mode(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[395], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_interest_rate_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[396], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_liability(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[397], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_max_borrowable(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[398], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_position_tiers(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[399], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_repayment_available_amount(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[400], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_set_auto_repay_mode(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[401], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_set_leverage(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[402], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_state(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[403], fields, nfields, out);
}

bybit_err bybit_spot_margin_trade_switch_mode(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[404], fields, nfields, out);
}

bybit_err bybit_spot_x_launchpool_project_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[405], fields, nfields, out);
}

bybit_err bybit_spot_x_launchpool_user_activity_log(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[406], fields, nfields, out);
}

bybit_err bybit_spot_x_launchpool_user_current_staking(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[407], fields, nfields, out);
}

bybit_err bybit_spot_x_launchpool_user_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[408], fields, nfields, out);
}

bybit_err bybit_spot_x_puzzle_project_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[409], fields, nfields, out);
}

bybit_err bybit_spot_x_token_splash_project_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[410], fields, nfields, out);
}

bybit_err bybit_spot_x_token_splash_user_activity_params(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[411], fields, nfields, out);
}

bybit_err bybit_spread_execution_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[412], fields, nfields, out);
}

bybit_err bybit_spread_instrument(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[413], fields, nfields, out);
}

bybit_err bybit_spread_max_qty(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[414], fields, nfields, out);
}

bybit_err bybit_spread_order_amend(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[415], fields, nfields, out);
}

bybit_err bybit_spread_order_cancel(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[416], fields, nfields, out);
}

bybit_err bybit_spread_order_cancel_all(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[417], fields, nfields, out);
}

bybit_err bybit_spread_order_create(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[418], fields, nfields, out);
}

bybit_err bybit_spread_order_history(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[419], fields, nfields, out);
}

bybit_err bybit_spread_order_realtime(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[420], fields, nfields, out);
}

bybit_err bybit_spread_orderbook(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[421], fields, nfields, out);
}

bybit_err bybit_spread_recent_trade(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[422], fields, nfields, out);
}

bybit_err bybit_spread_tickers(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[423], fields, nfields, out);
}

bybit_err bybit_strategy_create(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[424], fields, nfields, out);
}

bybit_err bybit_strategy_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[425], fields, nfields, out);
}

bybit_err bybit_strategy_order_list(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[426], fields, nfields, out);
}

bybit_err bybit_strategy_stop(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[427], fields, nfields, out);
}

bybit_err bybit_system_status(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[428], fields, nfields, out);
}

bybit_err bybit_user_aff_customer_info(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[429], fields, nfields, out);
}

bybit_err bybit_user_agreement(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[430], fields, nfields, out);
}

bybit_err bybit_user_create_demo_member(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[431], fields, nfields, out);
}

bybit_err bybit_user_create_sub_api(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[432], fields, nfields, out);
}

bybit_err bybit_user_create_sub_member(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[433], fields, nfields, out);
}

bybit_err bybit_user_del_submember(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[434], fields, nfields, out);
}

bybit_err bybit_user_delete_api(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[435], fields, nfields, out);
}

bybit_err bybit_user_delete_sub_api(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[436], fields, nfields, out);
}

bybit_err bybit_user_escrow_sub_members(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[437], fields, nfields, out);
}

bybit_err bybit_user_frozen_sub_member(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[438], fields, nfields, out);
}

bybit_err bybit_user_get_member_type(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[439], fields, nfields, out);
}

bybit_err bybit_user_invitation_code(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[440], fields, nfields, out);
}

bybit_err bybit_user_invitation_referrals(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[441], fields, nfields, out);
}

bybit_err bybit_user_query_api(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[442], fields, nfields, out);
}

bybit_err bybit_user_query_sub_members(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[443], fields, nfields, out);
}

bybit_err bybit_user_sub_apikeys(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[444], fields, nfields, out);
}

bybit_err bybit_user_submembers(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[445], fields, nfields, out);
}

bybit_err bybit_user_update_api(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[446], fields, nfields, out);
}

bybit_err bybit_user_update_sub_api(bybit_client *client, const bybit_kv *fields, size_t nfields, bybit_response **out)
{
    return bybit_endpoint_invoke(client, &bybit_endpoint_table[447], fields, nfields, out);
}

